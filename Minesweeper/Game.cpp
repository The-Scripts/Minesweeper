#include "Game.h"

using namespace std;
using namespace sf;

// Private methods
// Window
void Game::initVars()
{
	this->window = nullptr;
}

//Function initiating fonts
void Game::initFonts() {
    Font timersFont; Font bombIndicatorFont;
    if (!timersFont.loadFromFile("Resources/fonts/Pixellettersfull.ttf"))
    {
        cout << "# The font did'n load! #" << endl;
        cout << "# Pixellettersfull.ttf #" << endl;
    }
    if (!timersFont.loadFromFile("Resources/fonts/Cabal.ttf"))
    {
        cout << "# The font did'n load! #" << endl;
        cout << "# Cabal.ttf            #" << endl;
    }
    Text test; test.setFont(timersFont); test.setString("Hello World!"); window->draw(test);

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
    this->initFonts();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::update()
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
