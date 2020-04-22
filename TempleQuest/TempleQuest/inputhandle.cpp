#include "inputhandle.h"

// ---- Commands need to be initialized here ----
InputHandler::InputHandler()
{
	// jump = new jmpCommand; this is an example, a jump command could be created in commands.cpp
	assignKeys();
}

// ---- If entity is a player, the players commands are all handled here ----
Command* InputHandler::handleInput(Entity& ent)
{
	float velocity = ent.getVelo();
	// the input handler will designate movement to call directly to its respected function
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["FORWARD_KEY"]))) { (ent.getBod())->move(0, -velocity); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["DOWN_KEY"])))	  { (ent.getBod())->move(0, velocity);  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["RIGHT_KEY"])))   { (ent.getBod())->move(velocity, 0);  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["LEFT_KEY"])))    { (ent.getBod())->move(-velocity, 0); }

	// these commands here will return and run its specific command within COMMANDS

	return nullptr;
}

// ---- The main call function, takes in an entity and performs a command ----
void InputHandler::assignCommand(Entity& ent)
{ 
	Command* command = nullptr;

	// if the entity is a player, check for keyboard input
	if (ent.isPlayer()) { command = handleInput(ent); }

	// if the entity is not a player (an AI), read its AI function and it will return a command
	else { /* return a command from an ai class */ }

	// if (command) just basically means is there a command to check? if so, then run that command
	if (command)
	{
		command->run(ent);
	}
}

// ---- Assigns key bindings based off of a file ----
void InputHandler::assignKeys()
{
	std::ifstream keyBind;
	keyBind.open("Keybindings.txt"); // this ini file contains all the supported keys the user can map 

	if (!keyBind)
	{
		std::cout << "**ERROR: 'Keybindings.txt' NOT FOUND**" << std::endl;
	}

	// the key ID states where to hold the key in the map above, for example FORWARD_KEY will be stored into the ID and the key will be 'W'
	// so now when the player looks up keyID FORWARD_KEY, it displays W, which then can be inserted into the handleInput for its respective key
	std::string keyID;
	char key;

	while (!keyBind.eof())
	{
		// read in the values
		keyBind >> keyID;
		keyBind >> key;
		// store the values
		keyMap[keyID] = (key - 65); // we subtract 65 because for ASCII, A = 65, however for SFML A = 0, everything after that is in linear order
	}
	keyBind.close();
}
