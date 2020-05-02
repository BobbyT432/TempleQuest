#include "player.h"

void Player::draw(sf::RenderWindow& window)
{
	window.setView(FOV);
	
	// ---- Overrided because setView needs to be called before drawing ----
	window.draw(*entity);
	window.draw(healthBar);
}

void Player::onInteract()
{
	Entity* ent, * temp;
	
	for (std::list<Entity*>::iterator it = entGroup.begin(); it != entGroup.end(); ++it)
	{
		temp = *it;
		
		if ((temp->getPos().x <= this->getPos().x + atkRange) && (temp->getPos().x >= this->getPos().x - atkRange))
		{
			if ((temp->getPos().y <= this->getPos().y + atkRange) && (temp->getPos().y >= this->getPos().y - atkRange))
			{
			
					ent = temp;
					if (ent->isPlayer() == 0)
					{
						ent->minusHP(hpDealt);
						if (ent->getPos().x < this->getPos().x) { ent->getEnt()->move(-knockback, 0); }
						if (ent->getPos().x > this->getPos().x) { ent->getEnt()->move(knockback, 0); }
						if (ent->getPos().y < this->getPos().y) { ent->getEnt()->move(0, -knockback); }
						if (ent->getPos().y > this->getPos().y) { ent->getEnt()->move(0, knockback); }
					}
			}
		}
	}
	
}

void Player::updateHealth()
{
	// ---- This is kind of ugly but oh well ----
	if (hp == 8) { health->setStatic(0, 0); }
	if (hp == 7.5) { health->setStatic(0, 1); }
	if (hp == 7) { health->setStatic(1, 0); }
	if (hp == 6.5) { health->setStatic(1, 1); }
	if (hp == 6) { health->setStatic(2, 0); }
	if (hp == 5.5) { health->setStatic(2, 1); }
	if (hp == 5) { health->setStatic(3, 0); }
	if (hp == 4.5) { health->setStatic(3, 1); }
	if (hp == 4) { health->setStatic(4, 0); }
	if (hp == 3.5) { health->setStatic(4, 1); }
	if (hp == 3) { health->setStatic(5, 0); }
	if (hp == 2.5) { health->setStatic(5, 1); }
	if (hp == 2) { health->setStatic(6, 0); }
	if (hp == 1.5) { health->setStatic(6, 1); }
	if (hp == 1) { health->setStatic(7, 0); }
	if (hp == 0.5) { health->setStatic(7, 1); }
}

Player::Player()
{
	// ---- Players attributes ----
	collider = true;
	controllable = 1; // this just says that this entity is indeed a player (this is used in the input handler portion of the code)
	velocity = 0.9;
	currentDir = DOWN;
	hp = 8;
	atkRange = 10;
	knockback = 20;
	hpDealt = 1;

	// ---- Animate row variables ----
	forwardRow = 2;
	downRow = 1;
	leftRow = 3;
	rightRow = 4;
	attackFRow = 5;
	attackDRow = 8;
	attackLRow = 6;
	attackRRow = 7;
	DDRow = 0;
	DDColumn = 5;
	maxAnim = 6; 

	// ---- Set health bar ----
	hpBar.loadFromFile("textures/hp.png");
	healthBar.setTexture(&hpBar);
	healthBar.setSize(sf::Vector2f(100, 25));
	health = new Animation(&hpBar, sf::Vector2f(2, 8), 0);
	
	// ---- Create the player ----
	entity = new sf::RectangleShape(sf::Vector2f(34, 34));// This is the players figure (its a rectangle to represent the texture which is shaped like so)
	// ORIGINAL: size 100, 100, zoom 0.7, velocity 2 animation 0.07
	// ---- Size of the FOV ----
	FOV.setSize(sf::Vector2f(1920, 1080));
	FOV.zoom(0.2);

	entity->setPosition(607, 2524); 
	// ---- Assign textures ---- (THIS MAY BE REMOVED)
	entTexture = new sf::Texture();
	entTexture->loadFromFile("textures/player.png");
	entity->setTexture(entTexture);
	
	animate = new Animation(entTexture, sf::Vector2f(6, 9), 0.07); // the reason i did (7.8, 8.7), is because x represents how many sprites, by giving it more leeway it'l skew the image a bit more
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

// ---- Update will work hand in hand with the main game loop, cleans up the loop a bit and allows us to organize what needs to be updated JUST for the player ----
bool Player::update(float deltaTime)
{
	//std::cout << "X: " << getPos().x << "Y: " << getPos().y << std::endl;
	// ---- Input handling ----
	isControl = inputHandler.assignCommand(*this, deltaTime, *col); 

	// ---- Animation ----
	entity->setTextureRect(animate->uvRect); // ok so uvRect has the SIZE of the box that hovers over the texture file (since entity already has a texture from the player constructor)
	healthBar.setTextureRect(health->uvRect);
	// ---- Health ----
	updateHealth();
	healthBar.setPosition(sf::Vector2f(this->getPos().x - 165, this->getPos().y - 85));
	if (hp <= 0) { return 0; }

	// ---- Update view ----
	// ORIGINAL + 32, + 40
	FOV.setCenter(sf::Vector2f(entity->getPosition().x + 10, entity->getPosition().y + 20)); // dont ask why we have to set these values manually, I've tried getting the sprites dimensions and doing an eqn but nope

	// ---- If they were walking right, their idle animation needs to be right, etc ----
	if (!isControl && hp > 0)
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





