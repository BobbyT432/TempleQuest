#include "elderjoh.h"

ElderJoh::ElderJoh()
{
	srand(time(NULL)); // for random directions

	// ---- Players attributes ----
	collider = true;
	velocity = 0.4;
	currentDir = DOWN;
	atkRange = 10;
	targetAggro = 125;
	knockback = 10;
	hp = 100;
	hpDealt = 0.5;

	// ---- Create the player ----
	entity = new sf::RectangleShape(sf::Vector2f(24, 24));// This is the players figure (its a rectangle to represent the texture which is shaped like so)

	entity->setPosition(0, 0);
	// ---- Assign textures ---- (THIS MAY BE REMOVED)
	entTexture = new sf::Texture();
	entTexture->loadFromFile("textures/elderJoh.png");
	entity->setTexture(entTexture);

	animate = new Animation(entTexture, sf::Vector2f(2, 5), 0.07); // the reason i did (7.8, 8.7), is because x represents how many sprites, by giving it more leeway it'l skew the image a bit more
	//entTexture->setSmooth(true);

	// ---- Animate row variables ----
	forwardRow = 1;
	downRow = 0;
	leftRow = 3;
	rightRow = 2;
	DDRow = 0;
	DDColumn = 0;
	maxAnim = 2; // max row animations
}

void ElderJoh::draw(sf::RenderWindow& window)
{
	window.draw(*entity);
}

Command* ElderJoh::basicAI(Entity& ent)
{
	if (entity->getPosition().x > 345)
	{
		return new leftCom;
	}

	
	return nullptr;
}

void ElderJoh::setTarget(sf::Vector2f targetPos_)
{
	targetPos = targetPos_; // update the position of the area to follow (for AI)
}

void ElderJoh::updateEvent()
{
	
}

void ElderJoh::onInteract()
{
	
}

bool ElderJoh::update(float deltaTime)
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
		case FORWARD: animate->setStatic(2, 0);
			break;
		case RIGHT: animate->setStatic(0, 1);
			break;
		case DOWN: animate->setStatic(3, 0);
			break;
		case LEFT: animate->setStatic(3, 1);
			break;
		}
	}
}
