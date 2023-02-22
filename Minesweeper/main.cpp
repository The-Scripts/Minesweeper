#include "SpriteImage.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(480, 640), "Minesweeper", Style::Titlebar | Style::Close);

void initCells(Cell * cells);
void setBombs(Cell * cells);

int main()
{
    SpriteImage timer("../Resources/icons/clock-icon.png", 1.f, 1.f, 365.f, 2.f);
    Cell cells[256];

    // Init Fonts (temporary script)
    Font timersFont; Font bombIndicatorFont;
    if (!timersFont.loadFromFile("../Resources/fonts/Pixellettersfull.ttf") || !timersFont.loadFromFile("../Resources/fonts/Cabal.ttf"))
        cout << "# The fonts did'n load! #" << endl << "# Pixellettersfull.ttf  #" << endl << "# Cabal.ttf             #" << endl;

    Text test; test.setFont(timersFont); test.setFillColor(Color::Red); test.setCharacterSize(24); test.setString("Hello World!");
    window.draw(test);//testowe linijki

    // Game loop
    while (window.isOpen())
    {
        // Polling events
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
            }
        }
        window.clear(Color(45, 45, 45, 255));
        window.draw(timer.sprite);
        initCells(cells);
        window.display();
        
    }
    
    // End of the app
    return 0;
}

// Function that render game board
void initCells(Cell * cells)
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
        window.draw(cells[i].cellRender("../Resources/cells/blue-cell.png", 0.27f, 0.27f, gapX, gapY));
        gapX += 26;
    }
}

void setBombs(Cell* cells)
{
    const short ceil = 16;
    const short amtOfBombs = 20;
    short posX[20] { 0 };
    short posY[20] { 0 };
    short tempNumb;
    bool found;

    

    // Providing a seed value
    srand((unsigned)time(NULL));

    for (short i = 0; i < amtOfBombs; i++)
    {
        do
        {
            tempNumb = (rand() % 16) + 1;
            found = false;
            for (short j = 0; j < amtOfBombs; j++)
            {
                
            }

        } while (found);
    }
}