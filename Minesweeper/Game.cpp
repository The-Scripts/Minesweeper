#include "Game.h"

using namespace std;
using namespace sf;

// Private methods
// Window
void Game::initVars()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 480;
	this->videoMode.width = 640;
	this->window = new RenderWindow(VideoMode(this->videoMode), "Minesweeper", Style::Titlebar | Style::Close);
}

// Public methods
// Constructors / Destructors
Game::Game()
{
	this->initVars();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::uptade()
{
    this->pullEvents();
}

void Game::pullEvents()
{
    // Event pooliong
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case Event::Closed:
            this->window->close();
            break;
        case Event::KeyPressed:
            if (this->event.key.code == Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Game::render()
{
    this->window->clear(Color(45, 45, 45, 255));
    
    //Draw game
    this->window->display();
}
