#ifndef INPUT
#define INPUT

#include <fstream>
#include <map>
#include "character.h"

/*
	Explanation: For an explanation on the command crap you see here, go to 'cmndmaster.h'
*/

// ---- Handles all command inputs, PLAYER and AI ----
class InputHandler
{
private: 
	bool atkAnim;
	bool death;
	sf::Clock atkClock;

	std::map<std::string, int> keyMap; // this will hold all key commands and their respective key ID
public:
	InputHandler();
	Command* handleInput(Character& ent);
	bool assignCommand(Character& ent, float deltaTime, Collision& col);

	// ---- Assigns key bindings ----
	void assignKeys();
};

#endif