#include "skeleman.h"

Skeleman::Skeleman()
{
	// ---- Players attributes ----
	collider = true;
	velocity = 0.6;
	currentDir = DOWN;

	// ---- Create the player ----
	entity = new sf::RectangleShape(sf::Vector2f(25, 32));// This is the players figure (its a rectangle to represent the texture which is shaped like so)

	entity->setPosition(230, 250);
	// ---- Assign textures ---- (THIS MAY BE REMOVED)
	entTexture = new sf::Texture();
	entTexture->loadFromFile("textures/skeleman_b.png");
	entity->setTexture(entTexture);

	animate = new Animation(entTexture, sf::Vector2f(3, 6.7), 0.07); // the reason i did (7.8, 8.7), is because x represents how many sprites, by giving it more leeway it'l skew the image a bit more
	//entTexture->setSmooth(true);

	// ---- Animate row variables ----
	forwardRow = 2;
	downRow = 3;
	leftRow = 1;
	rightRow = 0;
	maxAnim = 3; // max row animations
}

void Skeleman::draw(sf::RenderWindow& window)
{
	window.draw(*entity);
}

Command* Skeleman::basicAI(Entity& ent)
{
	if (targetPos.x < this->getPos().x && targetPos.y < this->getPos().y) { return new forwardLCom; }
	if (targetPos.x > this->getPos().x && targetPos.y < this->getPos().y) { return new forwardRCom; }
	if (targetPos.x < this->getPos().x && targetPos.y > this->getPos().y) { return new downLCom;    }
	if (targetPos.x > this->getPos().x && targetPos.y > this->getPos().y) { return new downRCom;	}
	if (targetPos.x < this->getPos().x && (targetPos.y >= this->getPos().y - 10) && (targetPos.y <= this->getPos().y + 10)) { return new leftCom; }
	if (targetPos.x > this->getPos().x) { return new rightCom;}
	if (targetPos.y > this->getPos().y) { return new downCom; }
	if (targetPos.y < this->getPos().y) { return new forwardCom; }

	return nullptr;
}

void Skeleman::setTarget(sf::Vector2f targetPos_)
{
	targetPos = targetPos_; // update the position of the area to follow (for AI)
}

void Skeleman::update(float deltaTime)
{
	// ---- Input handling ----
	isControl = inputHandler.assignCommand(*this, deltaTime, *col);

	// ---- Animation ----
	entity->setTextureRect(animate->uvRect); // ok so uvRect has the SIZE of the box that hovers over the texture file (since entity already has a texture from the player constructor)

	// ---- If they were walking right, their idle animation needs to be right, etc ----
	if (!isControl)
	{
		switch (currentDir)
		{
		case FORWARD: animate->setStatic(2, 0);
			break;
		case RIGHT: animate->setStatic(0, 1);
			break;
		case DOWN: animate->setStatic(3, 0);
			break;
		case LEFT: animate->setStatic(1, 1);
			break;
		}
	}
}
