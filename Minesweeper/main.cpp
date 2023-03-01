#include "SpriteImage.h"
#include "Cell.h"
#include "UncoverEmpty.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <array>

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(480, 640), "Minesweeper", Style::Titlebar | Style::Close);


void initCells(Cell* cells);
short setBombs(Cell* cells);
bool checkForMouseClick(const Sprite& sprite, RenderWindow& window);
void uncoverAllCells(Cell* cells);
void checkFlags(const short amtOfBombs, short* bombsPositions, short* flagsPositions, bool endGame);

Text timeTimer; //variable displayed as a clock

int minutesTimer = 0, secondsTimer = 0;
Clock clockTimer; //start the clock

void timerFun();


int main()
{
    SpriteImage timer("../Resources/icons/clock-icon.png", 1.f, 1.f, 365.f, 2.f);
    Cell cells[256];
    bool endGame{ false }; // Stopping game loop
    short bombPositions = setBombs(cells);
    const short amtOfBombs = 30;
    short flagsPositions[amtOfBombs]{ -1 };
    short flags{ 0 };

    // Init Fonts (temporary script)
    Font timersFont, bombIndicatorFont;
    if (!timersFont.loadFromFile("../Resources/fonts/Pixellettersfull.ttf") || !timersFont.loadFromFile("../Resources/fonts/Cabal.ttf"))
        cout << "# The fonts did'n load! #" << endl << "# Pixellettersfull.ttf  #" << endl << "# Cabal.ttf             #" << endl;

    timeTimer.setFont(timersFont); timeTimer.setPosition(sf::Vector2f(385, 30));

    // Game loop
    while (window.isOpen() && (endGame == false))
    {
        // Polling events
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            // Wiondow
            case Event::Closed:
                window.close();
                break;
            // Keyboard
            case Event::KeyReleased:
                switch (event.key.code)
                {
                case Keyboard::Escape:
                    window.close();
                    break;
                }
                break;
            // Mouse
            case Event::MouseButtonReleased:
                for (short i = 0; i < 256; i++)
                {
                    if (checkForMouseClick(cells[i].cellRender(0.27f, 0.27f, cells[i].getPosX(), cells[i].getPosY()), window))
                    {
                        // Uncover cell
                        if (event.mouseButton.button == Mouse::Left)
                        {
                            if (cells[i].getState() == 'b')
                            {
                                uncoverAllCells(cells);
                                endGame = true;
                            }
                            cells[i].setIsClick(true);
                            UncoverEmpty uncoverEmpty(cells, i);
                        }
                        // Flag
                        else if (event.mouseButton.button == Mouse::Right)
                        {
                            if (cells[i].getState() == 'f')
                            {
                                // Unflag
                                cells[i].setState('e');
                                cells[i].setIsClick(false);
                                flagsPositions[flags] = -1;
                                flags--;
                            } 
                            else if (flags < amtOfBombs && cells[i].getIsClick() == false)
                            {
                                // Set flag
                                cells[i].setState('f');
                                cells[i].setIsClick(true);
                                flags++;
                                flagsPositions[flags] = i;
                                if (flags == amtOfBombs)
                                    checkFlags(amtOfBombs, &bombPositions, flagsPositions, &endGame);
                            }
                        }
                    }
                }
                break;
            }
        }
        window.clear(Color(45, 45, 45, 255));
        window.draw(timer.sprite);
        initCells(cells);
        timerFun();
        window.draw(timeTimer); //display clock
        window.display();

        // Ending screen
        while (endGame)
        {
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case Keyboard::Escape:
                        window.close();
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
            window.clear(Color(45, 45, 45, 255));
            window.draw(timer.sprite);
            initCells(cells);
            window.draw(timeTimer); //display clock
            window.display();
        }
    }



    // End of the app
    return 0;
}

// Function that render game board
void initCells(Cell* cells)
{
    const float marginLeft = 28; // left gameboard margin
    float gapX = marginLeft;     // gap behind left-right cell
    float gapY = 160;            // gap behind top-bottom cell

    // drawing 256 cells
    for (unsigned short i = 0; i < 256; i++)
    {
        // if render 16 cells in row make new row 
        if (i % 16 == 0)
        {
            gapX = marginLeft;
            gapY += 26;
        }
        cells[i].setPosX(gapX);
        cells[i].setPosY(gapY);
        window.draw(cells[i].cellRender(0.27f, 0.27f, gapX, gapY));
        gapX += 26;
    }
}

// Function that set random cell to bomb
short setBombs(Cell* cells)
{
    const short amtOfBombs = 30;
    short posX[amtOfBombs]{ 0 };
    short posY[amtOfBombs]{ 0 };
    short bombPosition[amtOfBombs]{ 0 };
    // Get random number for position X and Y
    for (short i = 0; i < amtOfBombs; i++)
    {
        // Providing a seed value
        srand((unsigned)time(NULL));

        short tempX;
        short tempY;
        bool found;

        do
        {
            // Random
            tempX = (rand() % 16) + 1;
            tempY = (rand() % 16) + 1;
            found = false;
            for (short j = 0; j < amtOfBombs; j++)
            {
                // If temp position is repeat
                if (tempX * tempY == posX[j] * posY[j])
                    found = true;
            }

        } while (found);

        posX[i] = tempX;
        posY[i] = tempY;
    }

    // List of last cells
    const short firstCells[16]{ 0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240 };
    // List of last cells
    short lastCells[16]{ 15, 31, 47, 63, 79, 95, 111, 127, 159, 175, 191, 207, 223, 239, 255 };

    // Set bombs
    for (short i = 0; i < amtOfBombs; i++)
    {
        // -1 because arrays starts from 0 not 1
        const short bombLocation = (posX[i] * posY[i]) - 1;
        bombPosition[i] = bombLocation;
        // Set state on bomb
        cells[bombLocation].setState('b');

        bool bombOnFirstCell{ false };
        bool bombOnLastCell{ false };
        for (short i = 0; i < 16; i++)
        {
            // If bomb is on first cell
            if (bombLocation == firstCells[i])
            {
                bombOnFirstCell = true;
                // Right
                cells[bombLocation + 1].setNumb(cells[bombLocation + 1].getNumb() + 1);
                // Top
                cells[bombLocation + 16].setNumb(cells[bombLocation + 16].getNumb() + 1);
                // Upper right
                cells[bombLocation + 17].setNumb(cells[bombLocation + 17].getNumb() + 1);
                // Buttom
                cells[bombLocation - 16].setNumb(cells[bombLocation - 16].getNumb() + 1);
                // Lower right
                cells[bombLocation - 17].setNumb(cells[bombLocation - 17].getNumb() + 1);
                break;

            }
            // If bomb is on last cell
            else if (bombLocation == lastCells[i])
            {
                bombOnFirstCell = true;
                // Left
                cells[bombLocation - 1].setNumb(cells[bombLocation - 1].getNumb() + 1);
                // Upper left
                cells[bombLocation + 15].setNumb(cells[bombLocation + 15].getNumb() + 1);
                // Top
                cells[bombLocation + 16].setNumb(cells[bombLocation + 16].getNumb() + 1);
                // Lower left
                cells[bombLocation - 17].setNumb(cells[bombLocation - 17].getNumb() + 1);
                // buttom
                cells[bombLocation - 16].setNumb(cells[bombLocation - 16].getNumb() + 1);
                break;
            }
        }

        // If bomb isn't on first or last cell
        if (bombOnFirstCell == false && bombOnLastCell == false)
        {
            // Left
            cells[bombLocation - 1].setNumb(cells[bombLocation - 1].getNumb() + 1);
            // Right
            cells[bombLocation + 1].setNumb(cells[bombLocation + 1].getNumb() + 1);
            for (short j = 15; j < 18; j++)
            {
                // Top
                cells[bombLocation - j].setNumb(cells[bombLocation - j].getNumb() + 1);
                // Buttom
                cells[bombLocation + j].setNumb(cells[bombLocation + j].getNumb() + 1);
            }
        }
    }

    return *bombPosition;
}


//function that sets the time and displays the clock
void timerFun()
{

    Time elapsed = clockTimer.getElapsedTime();

    if (elapsed.asSeconds() >= 1.0) { //every 1 second

        elapsed += clockTimer.restart();
        secondsTimer++;

        if (secondsTimer == 60) { //every 1 minute

            minutesTimer++;
            secondsTimer = 0;
        }
        //cout << minutesTimer << ": " << secondsTimer << endl; //display the clock in the console
    }
    timeTimer.setString(to_string(minutesTimer) + ": " + to_string(secondsTimer)); //set clock time
}

bool checkForMouseClick(const Sprite& sprite, RenderWindow& window)
{

    int mouseX = sf::Mouse::getPosition().x;
    int mouseY = sf::Mouse::getPosition().y;

    Vector2i windowPosition = window.getPosition();

    if (mouseX > sprite.getPosition().x + windowPosition.x && mouseX < (sprite.getPosition().x + sprite.getGlobalBounds().width + windowPosition.x)
        && mouseY > sprite.getPosition().y + windowPosition.y + 30 && mouseY < (sprite.getPosition().y + sprite.getGlobalBounds().height + windowPosition.y + 30))
    {
        return true;
    }

    return false;

}

void uncoverAllCells(Cell* cells)
{
    for (short i = 0; i < 256; i++)
    {
        if (cells[i].getState() == 'b' && cells[i].getNumb() == -1)
            cells[i].setState('x');
        cells[i].setIsClick(true);
    }
}

void checkFlags(const short amtOfBombs, short* bombsPositions, short* flagsPositions, bool endGame)
{
    short flagsOnBombs{ 0 };
    for (short i = 0; i < amtOfBombs; i++)
    {
        if (bombsPositions[i] == flagsPositions[i])
            flagsOnBombs++;
    }
    if (flagsOnBombs == 20)
        endGame = true;
}