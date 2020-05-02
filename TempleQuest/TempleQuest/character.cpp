#include "character.h"

void Character::setTarget(sf::Vector2f targetPos)
{
	targetPos = sf::Vector2f(0, 0);
}

Command* Character::basicAI(Entity& ent)
{
	return nullptr;
}
