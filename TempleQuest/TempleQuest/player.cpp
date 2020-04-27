#include "player.h"

void Player::draw(sf::RenderWindow& window)
{
	window.setView(FOV);
	
	// ---- Overrided because setView needs to be called before drawing ----
	window.draw(*entity);
}

Player::Player()
{
	// ---- Players attributes ----
	collider = true;
	controllable = 1; // this just says that this entity is indeed a player (this is used in the input handler portion of the code)
	velocity = 0.9;
	currentDir = DOWN;

	// ---- Create the player ----
	entity = new sf::RectangleShape(sf::Vector2f(32, 32));// This is the players figure (its a rectangle to represent the texture which is shaped like so)
	// ORIGINAL: size 100, 100, zoom 0.7, velocity 2 animation 0.07
	// ---- Size of the FOV ----
	FOV.setSize(sf::Vector2f(1920, 1080));
	FOV.zoom(0.2);

	// ---- Assign textures ---- (THIS MAY BE REMOVED)
	entTexture = new sf::Texture();
	entTexture->loadFromFile("textures/player.png");
	entity->setTexture(entTexture);
	
	animate = new Animation(entTexture, sf::Vector2f(7.8, 8.7), 0.07); // the reason i did (7.8, 8.7), is because x represents how many sprites, by giving it more leeway it'l skew the image a bit more
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
	// ---- Input handling ----
	isControl = inputHandler.assignCommand(*this, deltaTime); 

	// ---- Animation ----
	entity->setTextureRect(animate->uvRect); // ok so uvRect has the SIZE of the box that hovers over the texture file (since entity already has a texture from the player constructor)

	// ---- Update view ----
	// ORIGINAL + 32, + 40
	FOV.setCenter(sf::Vector2f(entity->getPosition().x + 10, entity->getPosition().y + 20)); // dont ask why we have to set these values manually, I've tried getting the sprites dimensions and doing an eqn but nope

	// ---- If they were walking right, their idle animation needs to be right, etc ----
	if (!isControl)
	{
		switch (currentDir)
		{
		case FORWARD: animate->setStatic(0, 2);
			break;
		case RIGHT: animate->setStatic(0, 4);
			break;
		case DOWN: animate->setStatic(0, 0);
			break;
		case LEFT: animate->setStatic(0, 3);
			break;
		}
	}
}


