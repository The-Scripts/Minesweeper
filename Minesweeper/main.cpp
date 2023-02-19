#include "Game.h"

using namespace std;
using namespace sf;

int main()
{
    // Init game engine
    Game game;


    // Game loop
    while (game.running())
    {
        // Uptade
        game.update();
        // Render
        game.render();
    }

    
    // End of the app

    return 0;
}