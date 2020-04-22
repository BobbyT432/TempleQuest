#include "player.h"

Player::Player()
{
	collider = true;
	player = 1; // this just says that this entity is indeed a player (this is used in the input handler portion of the code)
	playerBod = new sf::RectangleShape(sf::Vector2f(100, 100));// TEST, will be removed
	velocity = 10;
}

Player::~Player()
{
	std::cout << "**Player Deleted**" << std::endl; 
}

sf::RectangleShape* Player::getBod()
{
	return playerBod;
}

