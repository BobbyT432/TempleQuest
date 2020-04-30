#ifndef COLLISION
#define COLLISION

#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <list>

// This is not an efficent way to do collisions but we have 2 days left and I gotta get it done
class Collision
{
private:
	float gridSize;
	int gridBoxSz;
	
	struct gridNode
	{
		bool collider;
		sf::Vector2f gridPos;
		sf::Vector2i gridID;
		sf::RectangleShape gridBox;
	};
	std::list<gridNode> gridList;
public:
	Collision(std::string colLoc_, float gridSize_);
	void loadCol(std::string colLoc_);
	bool getGridCol(sf::Vector2i gridLoc);
	sf::Vector2i getGridLoc(sf::Vector2f entPos_);
};

#endif