#ifndef SKELEMAN
#define SKELEMAN

//#include "entity.h"
#include "inputhandle.h"
//#include "commands.h"
#include "character.h"

class Skeleman : public Character
{
private:
	// ---- Unfortunately, we need to declare this in every Entity that needs input handling (like AI), its because InputHandler depends on entity and entity would depend on InputHandler (circular dependency) ----
	InputHandler inputHandler;

	sf::Vector2f targetPos;
public:
	Skeleman();

	// ---- Once per frame ----
	void update(float deltaTime);  // target position to follow
	void draw(sf::RenderWindow& window);

	// ---- AI ----
	Command* basicAI(Entity& ent);
	void setTarget(sf::Vector2f targetPos_);
};

#endif

