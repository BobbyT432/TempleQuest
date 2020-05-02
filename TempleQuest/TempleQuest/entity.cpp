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

void Entity::setGroup(std::list<Entity*> &entGroup_)
{
	entGroup = entGroup_;
}

std::list<Entity*>* Entity::getGroup()
{
	return &entGroup;
}

sf::RectangleShape* Entity::getEnt()
{
	return entity;
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(*entity);
}

void Entity::setDir(dir dir_)
{
	currentDir = dir_;
}

dir Entity::getDir()
{
	return currentDir;
}

float Entity::getFRow()
{
	return forwardRow;
}

float Entity::getDRow()
{
	return downRow;
}

float Entity::getLRow()
{
	return leftRow;
}

float Entity::getRRow()
{
	return rightRow;
}

float Entity::getAFRow()
{
	return attackFRow;
}

float Entity::getADRow()
{
	return attackDRow;
}

float Entity::getALRow()
{
	return attackLRow;
}

float Entity::getARRow()
{
	return attackRRow;
}

float Entity::getDDRow()
{
	return DDRow;
}

float Entity::getDDCol()
{
	return DDColumn;
}

float Entity::getAnim()
{
	return maxAnim;
}

void Entity::minusHP(float hp_)
{
	hp -= hp_;
}

void Entity::addHP(float hp_)
{
	hp += hp_;
}

float Entity::getHP()
{
	return hp;
}

void Entity::setCol(Collision& col_)
{
	col = &col_;
}

void Entity::setTarget(sf::Vector2f targetPos_)
{
	targetPos = targetPos_; // update the position of the area to follow (for AI)
}