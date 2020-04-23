#include "player.h"

Player::Player()
{
	// ---- Players attributes ----
	collider = true;
	controllable = 1; // this just says that this entity is indeed a player (this is used in the input handler portion of the code)
	velocity = 2;

	// ---- Create the player ----
	entity = new sf::RectangleShape(sf::Vector2f(100, 150));// This is the players figure (its a rectangle to represent the texture which is shaped like so)

	// ---- Assign textures ---- (THIS MAY BE REMOVED)
	entTexture = new sf::Texture();
	entTexture->loadFromFile("textures/player.png");
	entTexture->setSmooth(true);
	entity->setTexture(entTexture);
	// ok so we are going to be reading in a sprite sheet, we need to get the SIZE of that sprite sheet and cut it up into proper animations
	// this helped a lot: https://www.youtube.com/watch?v=-mcnW_6QpYA
	sf::Vector2u texSize = entTexture->getSize(); // vector2u is vector to an unsigned int (anything positive), we need to get the size of the sprite sheet
	texSize.x /= 7.6; // how many penguins are on the x? getSize returns the size of the texture in PIXELS, so divide by 6 for 6 sprites 
	texSize.y /= 5.6;
	
	entity->setTextureRect(sf::IntRect(0, 0, texSize.x, texSize.y)); // (left coordinate, right coordinate, width, height)
	
	// ---- Error check ----
	if (!entTexture) { std::cout << "**PLAYER.PNG NOT FOUND**" << std::endl; }
}

Player::~Player()
{
	std::cout << "**Player Deleted**" << std::endl; 
	delete entTexture;
	delete entity;
}

sf::RectangleShape* Player::getEnt()
{
	return entity;
}


