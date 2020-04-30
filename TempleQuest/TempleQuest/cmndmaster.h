#ifndef COMMAND
#define COMMAND

#include "entity.h"
#include "animation.h"

// based off of: https://gameprogrammingpatterns.com/command.html
/*
	Explanation: Command is the BASE class which commands.h will derive off of. The way this works is that specific commands are needed in the game,
	such as attacking, cut scenes, etc. This base class here only has a 'run' function, which means execute the code for that command. The 'commands.h' file
	is where new commands are created, so if we want there to be a HIT command, then we create that command in commands.h.

	Now the way commands are read are in inputhandle.h, the input handler will check to see if a specific key was pressed like 'space' for jump, which will then call
	a jump object (instantiated from the jump class which is created in commands.h) and then execute that jump objects 'run' function. The input handler also accepts an argument
	for an entity, so it will read the entity.h file and see if the entity is a player or not. (This may be a bad way to do it, but idk how else I would have a checker to see if the entity
	is a player or not). If the entity is a player, it will do as I said above, scan the input to see if the player presses 'space'. 

	If the entity is NOT a player, it will then read from that entitys AI function, which will return a COMMAND, which will then EXECUTE that command on that entity. This way we can have an easy way
	to create a jump command that works for both a PLAYER and an AI.

	This may also be an overcomplicated way but i spent way too many hours on it im scared to remove it
*/
class Command // handles all user input
{
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col) = 0;
	virtual ~Command() = default;
};
#endif