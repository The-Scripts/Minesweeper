#include "SpriteImage.h"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(480, 640), "Minesweeper", Style::Titlebar | Style::Close);
    SpriteImage timer("../Resources/icons/clock-icon.png", 1.f, 1.f, 365.f, 2.f);

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
        window.display();
    }

    
    // End of the app

    return 0;
}