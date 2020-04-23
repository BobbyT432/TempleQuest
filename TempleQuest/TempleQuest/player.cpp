#include "player.h"


Player::Player()
{
	// ---- Players attributes ----
	collider = true;
	controllable = 1; // this just says that this entity is indeed a player (this is used in the input handler portion of the code)
	velocity = 2;

	// ---- Create the player ----
	entity = new sf::RectangleShape(sf::Vector2f(100, 100));// This is the players figure (its a rectangle to represent the texture which is shaped like so)

	// ---- Assign textures ---- (THIS MAY BE REMOVED)
	entTexture = new sf::Texture();
	entTexture->loadFromFile("textures/player.png");
	
	entity->setTexture(entTexture);
	entTexture->setSmooth(false);
	hold = new Animation(entTexture, sf::Vector2f(7.6, 1), 0.07);

	// ok so we are going to be reading in a sprite sheet, we need to get the SIZE of that sprite sheet and cut it up into proper animations
	// this helped a lot: https://www.youtube.com/watch?v=-mcnW_6QpYA
	
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

void Player::update(float deltaTime)
{
	

	hold->update(0, deltaTime);
	entity->setTextureRect(hold->uvRect);
}


