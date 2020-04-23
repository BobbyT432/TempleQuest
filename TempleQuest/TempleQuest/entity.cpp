#include "entity.h"

Entity::Entity()
{
	sf::Vector2f pos = sf::Vector2f(0, 0);
	controllable = 0;
	collider = 0;

	entity = nullptr;
	entTexture = nullptr;

	velocity = 0;
	hp = 0;
}

sf::Vector2f Entity::getPos()
{
	// return the objects position
	return entity->getPosition();
}

bool Entity::isPlayer()
{
	if (controllable == 0) { return false; }
	else { return true; }
}

float Entity::getVelo()
{
	return velocity;
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(*entity);
}
