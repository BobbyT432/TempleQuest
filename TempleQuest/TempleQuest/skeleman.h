#ifndef SKELEMAN
#define SKELEMAN

//#include "entity.h"
#include "inputhandle.h"
//#include "commands.h"
#include "character.h"
#include <time.h>
#include <stdlib.h>

class Skeleman : public Character
{
private:
	// ---- Unfortunately, we need to declare this in every Entity that needs input handling (like AI), its because InputHandler depends on entity and entity would depend on InputHandler (circular dependency) ----
	InputHandler inputHandler;

public:
	Skeleman();

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

