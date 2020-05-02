#ifndef ELDERJOH
#define ELDERJOH

#include "character.h"
#include "inputhandle.h"

class ElderJoh : public Character
{
private:
	// ---- Unfortunately, we need to declare this in every Entity that needs input handling (like AI), its because InputHandler depends on entity and entity would depend on InputHandler (circular dependency) ----
	InputHandler inputHandler;

public:
	ElderJoh();

	// ---- Once per frame ----
	bool update(float deltaTime);  // target position to follow
	void draw(sf::RenderWindow& window);

	// ---- AI ----
	Command* basicAI(Entity& ent);
	void setTarget(sf::Vector2f targetPos_);

	// ---- Event Handling ----
	void updateEvent();

	// ---- TESTING ----
	void onInteract();
};
#endif


