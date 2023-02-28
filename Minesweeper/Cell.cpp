#include "Cell.h"

// Public
Cell::Cell()
{
	this->state = 'e';
	this->click = false;
	this->numb = 0;
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
		if (click)
			switch (numb)
			{
			case 0:
				path = "../Resources/cells/gray-cell.png";
				break;
			case 1:
				path = "../Resources/cells/1-cell.png";
				break;
			case 2:
				path = "../Resources/cells/2-cell.png";
				break;
			case 3:
				path = "../Resources/cells/3-cell.png";
				break;
			case 4:
				path = "../Resources/cells/4-cell.png";
				break;
			case 5:
				path = "../Resources/cells/5-cell.png";
				break;
			case 6:
				path = "../Resources/cells/6-cell.png";
				break;
			case 7:
				path = "../Resources/cells/7-cell.png";
				break;
			case 8:
				path = "../Resources/cells/8-cell.png";
				break;
			}
		else
			path = "../Resources/cells/blue-cell.png";
		break;
	case 'b':
		if (click)
			path = "../Resources/cells/bomb-cell.png";
		else
			path = "../Resources/cells/blue-cell.png";
		break;
	case 'x':
		path = "../Resources/cells/exploded-bomb-cell.png";
		break;
	case 'f':
		if (click)
			path = "../Resources/cells/flag-cell.png";
		else
			path = "../Resources/cells/blue-cell.png";
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

bool Cell::getIsClick()
{
	return this->click;
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

void Cell::setIsClick(bool isClick)
{
	this->click = isClick;
}