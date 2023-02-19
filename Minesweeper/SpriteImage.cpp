#include "SpriteImage.h"

// Public variables
Texture texture;
Sprite sprite;

SpriteImage::SpriteImage(String path)
{
	// When image deosn't exist
	if (!texture.loadFromFile(path))
	{
		std::cout << "Couldn't load image\n";
		exit;
	}

	// Set texture to sprite
	sprite.setTexture(texture);
	
}

SpriteImage::~SpriteImage()
{
}
