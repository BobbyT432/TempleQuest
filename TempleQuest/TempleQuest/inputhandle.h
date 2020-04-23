#ifndef INPUT
#define INPUT

#include <fstream>
#include <map>
#include "commands.h"

/*
	Explanation: For an explanation on the command crap you see here, go to 'cmndmaster.h'
*/

// ---- Handles all command inputs, PLAYER and AI ----
class InputHandler
{
private: 
	// --- Commands ----
	Command* forward;
	Command* down;
	Command* right;
	Command* left;

	// --- Diagonal Commands: I understand this is silly, I could've just left in normal movement and it would do diagonals, however now AI can access these commands and do the same ----
	// ---- Also now diagonals have their own functions, so we could do diagonal animations ----
	Command* downR;
	Command* downL;
	Command* forwardR;
	Command* forwardL;

	std::map<std::string, int> keyMap; // this will hold all key commands and their respective key ID
public:
	InputHandler();
	Command* handleInput(Entity& ent);
	void assignCommand(Entity& ent, float deltaTime);

	// ---- Assigns key bindings ----
	void assignKeys();
};

#endif