#ifndef PLAYER
#define PLAYER

#include "entity.h"
#include "animation.h"

// ---- The main players class ----
class Player : public Entity
{
private:
	
public:
	Animation* hold;
	Player();
	virtual ~Player();

	// --- This is the actual entity, this can be plugged into draw() and it will display the player ----
	virtual sf::RectangleShape* getEnt();

	void update(float deltaTime); // this will be removed
};
#endif