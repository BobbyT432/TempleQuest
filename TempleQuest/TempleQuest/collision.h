#ifndef COLLISION
#define COLLISION

#include "tilemap.h"
#include <vector>
#include <iostream>

// This is not an efficent way to do collisions but we have 2 days left and I gotta get it done
class Collision
{
private:
	float gridSize;
	int gridBoxSz;
	int rowSize;
	int columnSize;

	struct gridNode
	{
		bool collider;
		sf::Vector2f gridPos;
		sf::Vector2i gridID;
		sf::RectangleShape gridBox;
	};
	std::vector<gridNode> gridVector;
public:
	Collision(std::string colLoc_, float gridSize_);
	void loadCol(std::string colLoc_);
	bool getGridCol(sf::Vector2i gridLoc);
	sf::Vector2i getGridLoc(sf::Vector2f entPos_);
};

#endif