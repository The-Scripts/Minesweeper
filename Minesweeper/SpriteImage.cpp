#include "SpriteImage.h"

// Public variables
Texture texture;
Sprite sprite;

SpriteImage::SpriteImage(String path, float width, float height, float pos_x, float pos_y)
{
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
}

SpriteImage::~SpriteImage()
{
}
