#ifndef LEVELMANA
#define LEVELMANA

#include <iostream>
#include <list>
#include "entity.h"
#include "collision.h"
#include "tilemap.h"
/*
	This is the manager for all level related functions, I want to be able to create the levels by deriving this base class
	and putting all related level stuff in their own classes, then creating that object somewhere outside the game loop and passing
	it into the state machine
*/
class LevelManager
{
protected:
	Collision* col; // maps collision
	
	// ---- Tilemap layers ----
	TileMap* zero; // tilemap BEHIND the player 
	TileMap* one; // tilemap IN FRONT of the player 

	// ---- SFML properties ----
	sf::RenderWindow* window;

	// ---- Transition state ----
	bool transit; // if its 0, the player died, if its 1, time to transition to the next level

	std::list<Entity*> entGroup; // all entities in a given level
public:
	virtual unsigned int update(float deltaTime) = 0;
	virtual ~LevelManager() = default;
	virtual void draw() = 0;
};

#endif
