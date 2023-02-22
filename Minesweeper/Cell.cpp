#include "Cell.h"

// Public
Cell::Cell()
{
	this->state = 'e';
	clickOnBomb = false;
}

Cell::~Cell()
{
}

Sprite Cell::cellRender(float width, float height, float pos_x, float pos_y)
{
	String path;
	switch (this->state)
	{
	case 'e':
		path = "../Resources/cells/blue-cell.png";
		break;
	case 'b':
		if (clickOnBomb)
		{
			path == "../Resources/cells/bomb-cell.png";
		}
		else
		{
			path = "../Resources/cells/blue-cell.png";
		}
		break;
	case 'f':
		path = "../Resources/cells/flag-cell.png";
		break;
	}
	// When image deosn't exist
	if (!texture.loadFromFile(path))
	{
		std::cout << "Couldn't load image\n";
		exit;
	}

	// Set texture to sprite
	sprite.setTexture(texture);

	// Move sprite
	sprite.setPosition(pos_x, pos_y);

	// Set width and height
	sprite.setScale(Vector2f(width, height));
	return sprite;
}

// Getters
char Cell::getState()
{
	return this->state;
}

short Cell::getNumb()
{
	return this->numb;
}

float Cell::getPosX()
{
	return this->posX;
}

float Cell::getPosY()
{
	return this->posY;
}

// Setters
void Cell::setState(char state)
{
	this->state = state;
}

void Cell::setNumb(short numb)
{
	this->numb = numb;
}

void Cell::setPosX(float posX)
{
	this->posX = posX;
}

void Cell::setPosY(float posY)
{
	this->posY = posY;
}