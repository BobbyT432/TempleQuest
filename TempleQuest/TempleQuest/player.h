#ifndef PLAYER
#define PLAYER

#include "inputhandle.h"

// ---- The main players class ----
class Player : public Character
{
private:
	// ---- View support ----
	sf::View FOV;
	
	// ---- Unfortunately, we need to declare this in every Entity that needs input handling (like AI), its because InputHandler depends on entity and entity would depend on InputHandler (circular dependency) ----
	InputHandler inputHandler;

public:
	Player();
	virtual ~Player();

	// ---- Overrided from entity so we can set a view port ----
	virtual void draw(sf::RenderWindow& window);

	// sf::RectangleShape* getEnt();

	void update(float deltaTime); 

	
};
#endif