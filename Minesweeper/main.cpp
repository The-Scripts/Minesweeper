#include "SpriteImage.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <stdlib.h>


using namespace std;
using namespace sf;

RenderWindow window(VideoMode(480, 640), "Minesweeper", Style::Titlebar | Style::Close);


Text timeTimer;
    
void timerFun() {

    int minutesTimer = 0; int secondsTimer = 0;

    timeTimer.setString(minutesTimer + ":" + secondsTimer);
    sleep(seconds(1.0));
    secondsTimer++;

        if (secondsTimer == 60) {

            minutesTimer++;
            secondsTimer = 0;
        }
}

int main()
{
    SpriteImage timer("../Resources/icons/clock-icon.png", 1.f, 1.f, 365.f, 2.f);

    // Init Fonts (temporary script)
    Font timersFont, bombIndicatorFont;
    if (!timersFont.loadFromFile("../Resources/fonts/Pixellettersfull.ttf") || !timersFont.loadFromFile("../Resources/fonts/Cabal.ttf"))
        cout << "# The fonts did'n load! #" << endl << "# Pixellettersfull.ttf  #" << endl << "# Cabal.ttf             #" << endl;

    Text test; test.setFont(timersFont); test.setFillColor(Color::Red); test.setCharacterSize(24); test.setString("Hello World!");//testowe linijki

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
        timerFun();
        window.draw(timeTimer);
        window.display();
        
    }
    
    // End of the app
    return 0;
}