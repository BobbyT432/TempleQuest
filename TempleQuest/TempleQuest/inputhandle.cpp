#include "inputhandle.h"

// ---- Commands need to be initialized here ----
InputHandler::InputHandler()
{
	assignKeys(); // key bindings
	death = 0;
	atkAnim = 0;
}

// ---- If entity is a player, the players commands are all handled here ----
Command* InputHandler::handleInput(Character& ent)
{
	float velocity = ent.getVelo();
	// ---- OTHER ----
	if (ent.getHP() <= 0) { death = 1; return new deathCom; }
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { atkClock.restart(); atkAnim = 1; return new attackCom; }

	// ---- DIAGONALS ----
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["DOWN_KEY"])) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["RIGHT_KEY"]))) { return new downRCom; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["DOWN_KEY"])) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["LEFT_KEY"]))) { return new downLCom; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["FORWARD_KEY"])) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["RIGHT_KEY"]))) { return new forwardRCom; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["FORWARD_KEY"])) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["LEFT_KEY"]))) { return new forwardLCom; }

	// ---- BASIC 4 MOVEMENTS ----
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["FORWARD_KEY"]))) { return new forwardCom; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["DOWN_KEY"]))) { return new downCom; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["RIGHT_KEY"]))) { return new rightCom; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyMap["LEFT_KEY"]))) { return new leftCom; }
	
	
	return nullptr;
}

// ---- The main call function, takes in an entity and performs a command ----
bool InputHandler::assignCommand(Character& ent, float deltaTime, Collision &col)
{ 
	Command* command = nullptr;
	if (!death)
	{
		if (!atkAnim) // timer for the attack animation to play through
		{
			// if the entity is a player, check for keyboard input
			if (ent.isPlayer()) { command = handleInput(ent); }
			// if the entity is not a player (an AI), read its AI function and it will return a command
			else
			{
				if (ent.getHP() <= 0) { command = new deathCom; }
				else { command = ent.basicAI(ent); }
			}
		}
		else
		{
			if (atkClock.getElapsedTime().asSeconds() >= 0.25) { atkAnim = 0; }
			command = new attackCom;
		}
	}

	// if (command) just basically means is there a command to check? if so, then run that command
	if (command)
	{
		command->run(ent, deltaTime, col);
		return 1;
	}
	return 0;
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
