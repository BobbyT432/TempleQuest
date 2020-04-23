#include "player.h"

Player::Player()
{
	// ---- Players attributes ----
	collider = true;
	controllable = 1; // this just says that this entity is indeed a player (this is used in the input handler portion of the code)
	velocity = 2;
	currentDir = DOWN;

	// ---- Create the player ----
	entity = new sf::RectangleShape(sf::Vector2f(100, 100));// This is the players figure (its a rectangle to represent the texture which is shaped like so)

	// ---- Assign textures ---- (THIS MAY BE REMOVED)
	entTexture = new sf::Texture();
	entTexture->loadFromFile("textures/player.png");
	entity->setTexture(entTexture);

	animate = new Animation(entTexture, sf::Vector2f(7.6, 1), 0.07); // the reason i did (7.6, 1), is because x represents how many sprites, by giving it more leeway it'l skew the image a bit more
	//entTexture->setSmooth(true);

	
	
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

// ---- Update will work hand in hand with the main game loop, cleans up the loop a bit and allows us to organize what needs to be updated JUST for the player ----
void Player::update(float deltaTime)
{
	inputHandler.assignCommand(*this, deltaTime); 

	// ---- If they were walking right, their idle animation needs to be right, etc ----
	switch (currentDir)
	{
	case FORWARD: 
		break;
	case RIGHT:
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	}
}


