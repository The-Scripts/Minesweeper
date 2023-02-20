#include "SpriteImage.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(480, 640), "Minesweeper", Style::Titlebar | Style::Close);

void initFonts();
short* getRandom();

int main()
{
    SpriteImage timer("../Resources/icons/clock-icon.png", 1.f, 1.f, 365.f, 2.f);
    Cell cell;
   
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
        window.draw(cell.cellRender("../Resources/cells/blue-cell.png", 0.3f, 0.3f, 5.f, 150.f));
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

short* getRandom() {

    static short r[20];

    // set the seed
    srand((unsigned)time(NULL));

    for (int i = 0; i < 20; ++i) {
        r[i] = rand()%17;
        cout << r[i] << endl;
    }

    return r;
}