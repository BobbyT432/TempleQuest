#include "ganon.h"

Ganon::Ganon()
{
	// ---- Players attributes ----
	collider = true;
	velocity = 0.4;
	currentDir = DOWN;
	atkRange = 10;
	targetAggro = 125;
	knockback = 20;
	hp = 16;
	hpDealt = 2;

	// ---- Create the player ----
	entity = new sf::RectangleShape(sf::Vector2f(64, 64));// This is the players figure (its a rectangle to represent the texture which is shaped like so)

	entity->setPosition(230, 290);
	// ---- Assign textures ---- (THIS MAY BE REMOVED)
	entTexture = new sf::Texture();
	entTexture->loadFromFile("textures/ganon.png");
	entity->setTexture(entTexture);

	animate = new Animation(entTexture, sf::Vector2f(7, 3), 0.07); // the reason i did (7.8, 8.7), is because x represents how many sprites, by giving it more leeway it'l skew the image a bit more
	//entTexture->setSmooth(true);

	// ---- Animate row variables ----
	forwardRow = 1;
	downRow = 1;
	leftRow = 1;
	rightRow = 1;
	DDRow = 2;
	DDColumn = 3;
	maxAnim = 7; // max row animations
}

bool Ganon::update(float deltaTime)
{
	// ---- Input handling ----
	isControl = inputHandler.assignCommand(*this, deltaTime, *col);

	// ---- Animation ----
	entity->setTextureRect(animate->uvRect); // ok so uvRect has the SIZE of the box that hovers over the texture file (since entity already has a texture from the player constructor)

	// ---- Health ----
	if (hp <= 0) { return 0; }

	// ---- If they were walking right, their idle animation needs to be right, etc ----
	if (!isControl && hp > 0)
	{
		switch (currentDir)
		{
		case FORWARD: animate->setStatic(2, 2);
			break;
		case RIGHT: animate->setStatic(2, 2);
			break;
		case DOWN: animate->setStatic(2, 2);
			break;
		case LEFT: animate->setStatic(2, 2);
			break;
		}
	}
}

void Ganon::draw(sf::RenderWindow& window)
{
	window.draw(*entity);
}

Command* Ganon::basicAI(Entity& ent)
{
	if ((targetPos.x <= this->getPos().x + targetAggro) && targetPos.x >= this->getPos().x - targetAggro)
	{
		if ((targetPos.y <= this->getPos().y + targetAggro) && (targetPos.y >= this->getPos().y - targetAggro))
		{
			if ((targetPos.x <= this->getPos().x + atkRange) && (targetPos.x >= this->getPos().x - atkRange))
			{
				if ((targetPos.y <= this->getPos().y + atkRange) && (targetPos.y >= this->getPos().y - atkRange))
				{
					return new attackCom;
				}
			}
			if (targetPos.x < this->getPos().x && targetPos.y < this->getPos().y) { return new forwardLCom; }
			if (targetPos.x > this->getPos().x && targetPos.y < this->getPos().y) { return new forwardRCom; }
			if (targetPos.x < this->getPos().x && targetPos.y > this->getPos().y) { return new downLCom; }
			if (targetPos.x > this->getPos().x && targetPos.y > this->getPos().y) { return new downRCom; }
			if (targetPos.x < this->getPos().x && (targetPos.y >= this->getPos().y - 10) && (targetPos.y <= this->getPos().y + 10)) { return new leftCom; }
			if (targetPos.x > this->getPos().x) { return new rightCom; }
			if (targetPos.y > this->getPos().y) { return new downCom; }
			if (targetPos.y < this->getPos().y) { return new forwardCom; }
		}
	}
	return nullptr;
}

void Ganon::setTarget(sf::Vector2f targetPos_)
{
	targetPos = targetPos_; // update the position of the area to follow (for AI)
}

void Ganon::onInteract()
{
	Entity* ent, * temp;

	for (std::list<Entity*>::iterator it = entGroup.begin(); it != entGroup.end(); ++it)
	{
		temp = *it;
		ent = temp;
		if (ent->isPlayer() == 1)
		{
			ent->minusHP(hpDealt);

			// ---- Knockback in opposite direction ----
			if (ent->getPos().x < this->getPos().x) { ent->getEnt()->move(-knockback, 0); }
			if (ent->getPos().x > this->getPos().x) { ent->getEnt()->move(knockback, 0); }
			if (ent->getPos().y < this->getPos().y) { ent->getEnt()->move(0, -knockback); }
			if (ent->getPos().y > this->getPos().y) { ent->getEnt()->move(0, knockback); }
		}
	}
}
