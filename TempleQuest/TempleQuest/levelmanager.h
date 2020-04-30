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
	TileMap* back; // tilemap BEHIND the ground (water below a surface, etc)
	TileMap* ground; // tilemap BEHIND the player, (the ground, etc)
	TileMap* front; // tilemap IN FRONT of the player, (Bushes, etc)

	//std::list<Entity> entGroup; // all entities in a given level

	// ---- SFML properties ----
	sf::RenderWindow* window;
public:
	virtual void update(float deltaTime) = 0;
	virtual ~LevelManager() = default;
	virtual void draw() = 0;
};

#endif
