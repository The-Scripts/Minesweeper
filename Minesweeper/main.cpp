#include "SpriteImage.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(480, 640), "Minesweeper", Style::Titlebar | Style::Close);


Text timeTimer; //variable displayed as a clock

int minutesTimer = 0, secondsTimer = 0;
Clock clockTimer; //start the clock

void timerFun();

int main()
{
    SpriteImage timer("../Resources/icons/clock-icon.png", 1.f, 1.f, 365.f, 2.f);

    // Init Fonts (temporary script)
    Font timersFont, bombIndicatorFont;
    if (!timersFont.loadFromFile("../Resources/fonts/Pixellettersfull.ttf") || !timersFont.loadFromFile("../Resources/fonts/Cabal.ttf"))
        cout << "# The fonts did'n load! #" << endl << "# Pixellettersfull.ttf  #" << endl << "# Cabal.ttf             #" << endl;

    timeTimer.setFont(timersFont); timeTimer.setPosition(sf::Vector2f(385, 30));
    

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
        window.display();
        
    }
    
    // End of the app
    return 0;
}

//function that sets the time and displays the clock
void timerFun() {

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
    window.draw(timeTimer); //display clock
}
