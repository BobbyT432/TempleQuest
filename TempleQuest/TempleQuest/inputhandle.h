#ifndef INPUT
#define INPUT

#include <SFML/Graphics.hpp>
#include "cmndmaster.h"
#include "commands.h"
#include <fstream>
#include <map>

/*
	Explanation: For an explanation on the command crap you see here, go to 'cmndmaster.h'
*/
class InputHandler
{
private: 
	//Command* jump; // example of where you need to create a command to be returned 

	std::map<std::string, int> keyMap; // this will hold all key commands and their respective key ID
public:

	InputHandler();
	Command* handleInput(Entity& ent);
	void assignCommand(Entity& ent);

	// will change to a better UI later, but for debugging purposes keep below code
	void assignKeys();
};
#endif