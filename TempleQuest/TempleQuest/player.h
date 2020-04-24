#ifndef PLAYER
#define PLAYER

#include "inputhandle.h"

// ---- The main players class ----
class Player : public Entity
{
private:
	bool isControl;
	// ---- Unfortunately, we need to declare this in every Entity that needs input handling (like AI), its because InputHandler depends on entity and entity would depend on InputHandler (circular dependency) ----
	InputHandler inputHandler;
public:
	Player();
	virtual ~Player();

	// --- This is the actual entity, this can be plugged into draw() and it will display the player ----
	virtual sf::RectangleShape* getEnt();

	void update(float deltaTime); // CHANGE TO ALL ENTITIES
};
#endif