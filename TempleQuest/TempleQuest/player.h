#ifndef PLAYER
#define PLAYER

#include "entity.h"

class Player : public Entity
{
private:
	
public:
	
	Player();
	virtual ~Player();

	virtual sf::RectangleShape* getBod();
};
#endif