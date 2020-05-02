#ifndef GANON
#define GANON

#include "character.h"
#include "inputhandle.h"

class Ganon : public Character 
{
private:
	InputHandler inputHandler;

	sf::Vector2f targetPos;
public:
	Ganon();

	// ---- Once per frame ----
	bool update(float deltaTime);  // target position to follow
	void draw(sf::RenderWindow& window);

	// ---- AI ----
	Command* basicAI(Entity& ent);
	void setTarget(sf::Vector2f targetPos_);

	// ---- TESTING ----
	void onInteract();
};

#endif

