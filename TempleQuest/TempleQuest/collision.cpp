#include "collision.h"

Collision::Collision(std::string colLoc_, float gridSize_)
{
	gridSize = gridSize_;

	loadCol(colLoc_);
}

// ---- Loads collision data from CSV file ----
void Collision::loadCol(std::string colLoc_)
{
	std::string colLoc = colLoc_;
	
	int gridID[900]; // 900 is amount of tiles allowed
	int rowSize = std::sqrt(gridSize);
	int columnSize = std::sqrt(gridSize);
	gridBoxSz = 32;

	std::string temp;
	std::string data;
	int index = 0;
	std::ifstream colFile;

	colFile.open(colLoc);

	// ---- Reading in a CSV file is the most tedious thing ever ----
	while (std::getline(colFile, temp))
	{
		std::istringstream ss(temp);
		while (std::getline(ss, data, ','))
		{
			std::istringstream ss2(data);

			ss2 >> gridID[index];
			index++;
		}
	}

	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			gridNode* temp = new gridNode;

			temp->gridID = sf::Vector2i(column, row); // this is the position that we will use (like 0, 4)
			temp->gridPos = sf::Vector2f(column * gridBoxSz, row * gridBoxSz);
			temp->gridBox.setPosition(temp->gridPos);

			int curCol = gridID[column + (row * columnSize)]; // current collision ID

			temp->collider = curCol;
			
			gridList.emplace_front(*temp); // put the grids in a list
		}
	}
}

bool Collision::getGridCol(sf::Vector2i gridLoc)
{
	for (std::list<gridNode>::iterator it = gridList.begin(); it != gridList.end(); ++it) // iterator
	{
		if (it->gridID == gridLoc)
			return it->collider;
	}
	return -1; // the player is outside the map 
}

sf::Vector2i Collision::getGridLoc(sf::Vector2f entPos_)
{
	sf::Vector2f entPos = entPos_;

	for (std::list<gridNode>::iterator it = gridList.begin(); it != gridList.end(); ++it) // iterator
	{
		if (entPos.x > it->gridBox.getPosition().x && entPos.x < it->gridBox.getPosition().x + gridBoxSz)
		{
			if (entPos.y > it->gridBox.getPosition().y && entPos.y < it->gridBox.getPosition().y + gridBoxSz)
			{
				return it->gridID;
			}
		}
	}
}


