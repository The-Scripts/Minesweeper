#include "SpriteImage.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(480, 640), "Minesweeper", Style::Titlebar | Style::Close);

void initFonts();
void initCells(Cell * cells);

int main()
{
    SpriteImage timer("../Resources/icons/clock-icon.png", 1.f, 1.f, 365.f, 2.f);
    Cell cells[256];
   
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
        initFonts();
    }

    
    // End of the app

    return 0;
}

//Function initiating fonts
void initFonts() {

    Font timersFont; Font bombIndicatorFont;
    if (!timersFont.loadFromFile("../Resources/fonts/Pixellettersfull.ttf"))
    {
        cout << "# The font did'n load! #" << endl;
        cout << "# Pixellettersfull.ttf #" << endl;
    }
    if (!timersFont.loadFromFile("../Resources/fonts/Cabal.ttf"))
    {
        cout << "# The font did'n load! #" << endl;
        cout << "# Cabal.ttf            #" << endl;
    }
    Text test; test.setFont(timersFont); test.setFillColor(Color::Red); test.setCharacterSize(24); test.setString("Hello World!"); 
    window.draw(test);

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