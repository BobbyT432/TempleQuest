#ifndef CHARACTER
#define CHARACTER

#include "commands.h"

// commands NEED entity to work, entity NEEDS commands to enable AI, this is circular dependency, they both rely on each other
// my solution (which idk if this is bad) was to create a NEW class that derives from Entity, and all the functions that NEEDED commands
//  will be placed in here, so instead of it being in entity, it is a layer up and entity can now perform without the need for commands
class Character: public Entity
{
public:
	virtual void setTarget(sf::Vector2f targetPos);
	virtual Command* basicAI(Entity& ent);
};
#endif

