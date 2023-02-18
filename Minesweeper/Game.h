#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/*
	Class that acts as the game engine.
	Wrapper class.
*/

using namespace sf;

class Game
{
private:
	// Variables
	RenderWindow* window;
	VideoMode videoMode;
	Event event;

	// Methods
	void initVars();
	void initWindow();
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Methods
	void pullEvents();
	void uptade();
	void render();
};
