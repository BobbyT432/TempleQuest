#include "entity.h"

Entity::Entity()
{
	sf::Vector2f pos = sf::Vector2f(0, 0);
	player = 0;
	collider = 0;

	playerBod = new sf::RectangleShape(sf::Vector2f(0, 0));// to be removed
	float velocity = 0;
}

sf::Vector2f Entity::getPos()
{
	// return the objects position
	return playerBod->getPosition();
}

bool Entity::isPlayer()
{
	if (player == 0) { return false; }
	else { return true; }
}

float Entity::getVelo()
{
	return velocity;
}
