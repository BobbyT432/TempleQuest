#ifndef PLAYER
#define PLAYER

#include "entity.h"

// ---- The main players class ----
class Player : public Entity
{
private:
	
public:
	
	Player();
	virtual ~Player();

	// --- This is the actual entity, this can be plugged into draw() and it will display the player ----
	virtual sf::RectangleShape* getEnt();
};
#endif