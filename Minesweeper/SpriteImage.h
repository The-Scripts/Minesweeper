#pragma once

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "SFML/Graphics.hpp"

using namespace sf;

class SpriteImage
{
public:
	// Constructor and destructor
	// Constructor and destructor
	SpriteImage(String path);
	~SpriteImage();
	// Variables
	Texture texture;
	Sprite sprite;
};

