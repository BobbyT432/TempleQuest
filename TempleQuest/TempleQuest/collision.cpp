#include "collision.h"
#include "math.h"

#define COLSIZE 10000
Collision::Collision(std::string colLoc_, float gridSize_)
{
	gridSize = gridSize_;

	loadCol(colLoc_);
}

// ---- Loads collision data from CSV file ----
void Collision::loadCol(std::string colLoc_)
{
	std::string colLoc = colLoc_;
	
	int gridID[COLSIZE]; 
	rowSize = std::sqrt(gridSize);
	columnSize = std::sqrt(gridSize);
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

			int curCol = gridID[column + (row * columnSize)]; // current collision ID

			temp->collider = curCol;
			
			gridVector.push_back(*temp); // put the grids in a vector
		}
	}
}

bool Collision::getGridCol(sf::Vector2i gridLoc)
{
	int row = gridLoc.y;
	int column = gridLoc.x;

	return gridVector[column + (row * columnSize)].collider;

	//for (std::vector<gridNode>::iterator it = gridVector.begin(); it != gridVector.end(); ++it) // iterator
	//{
	//	if (it->gridID == gridLoc)
	//		return it->collider;
	//}
	return -1; // the player is outside the map 
}

sf::Vector2i Collision::getGridLoc(sf::Vector2f entPos_)
{
	sf::Vector2f entPos = entPos_;

	// ---- Are you serious? ONE LINE OF CODE IS ALL IT TOOK? ----
	return sf::Vector2i(std::floor(entPos.x / 32), std::floor(entPos.y / 32));


	// ---- INEFFICENT CODE BELOW ----
	// the process here will optimize our game, instead of checking every tile on the map to see where the entity is, depending
	// on its position it will start at a different index interval
	//int offset = 1;
	//// ---- I believe this is binary sort ----
	//if (entPos.x > 1080 / 2) {} // if he is on the right side of the screen


	/*for (index = 0; index < gridVector.size(); index += offset)
	{
		if (entPos.x > gridVector[index].gridBox.getPosition().x && entPos.x < gridVector[index].gridBox.getPosition().x + gridBoxSz)
			{
				if (entPos.y > gridVector[index].gridBox.getPosition().y && entPos.y < gridVector[index].gridBox.getPosition().y + gridBoxSz)
				{
						return gridVector[index].gridID;
				}
			}*/
	//}
	//for (std::vector<gridNode>::iterator it = gridVector.begin(); it != gridVector.end(); ++it) // iterator
	//{
	//	if (entPos.x > it->gridBox.getPosition().x && entPos.x < it->gridBox.getPosition().x + gridBoxSz)
	//	{
	//		if (entPos.y > it->gridBox.getPosition().y && entPos.y < it->gridBox.getPosition().y + gridBoxSz)
	//		{
	//			return it->gridID;
	//		}
	//	}
	//}
}


