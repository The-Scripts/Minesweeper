#pragma once

#include "SFML/Graphics.hpp"
#include "SpriteImage.h"

using namespace sf;

class Cell
{
private:
	// Variables
	char state; // f - flag, b - bomb, e - empty, u - uncover, x - exploded
	short numb;
	float posX;
	float posY;
	bool click;
	Sprite sprite;
	Texture texture;
public: 
	// Constructor and destructor
	Cell();
	~Cell();
	
	// Methods
	Sprite cellRender(float width, float height, float pos_x, float pos_y);
	// Getters
	char getState();
	short getNumb();
	float getPosX();
	float getPosY();
	bool getIsClick();
	// Setters
	void setState(char state);
	void setNumb(short numb);
	void setPosX(float posX);
	void setPosY(float posY);
	void setIsClick(bool isClick);
};