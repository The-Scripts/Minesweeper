#pragma once

#include "pch.h"

/*
	By the class we can:
	1. Create sprite by passing path in String path.
	2. Change size by passing float width and float height.
	3. Change position by passing float pos_x and float pos_y.
*/

using namespace sf;

class SpriteImage
{
public:
	// Constructor and destructor
	SpriteImage(String path, float width, float height, float pos_x, float pos_y);
	~SpriteImage();
	// Variables
	Texture texture;
	Sprite sprite;
};

