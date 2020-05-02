#include "tilemap.h"

TileMap::TileMap(std::string texLoc, std::string mapLoc_, sf::Vector2f tileSize, float mapWidth_, float mapHeight_)
{
	// ---- Whenever a new map with a NEW tile set is created, it'll read it in here, however we should stick to one file ----
	mapLoc = mapLoc_;
	map = new sf::Texture;
	map->loadFromFile(texLoc);
	tileWidth = tileSize.x;
	tileHeight = tileSize.y;
	mapWidth = mapWidth_;
	mapHeight = mapHeight_;
	tileCount.x = mapWidth / tileWidth; // how many tiles in x or y direction are needed
	tileCount.y = mapHeight / tileHeight;
	mapVerts.setPrimitiveType(sf::Quads);
	mapVerts.resize((mapWidth * mapHeight) * 4); // we need to size the ARRAY to fit the size of our LEVEL (the reason we * by 4 is because (i think) to account for each of its 4 vertices
	// one quad has 4 vertices, and you need the area of the map to get the amount of quads you need, and since each quad has 4 vertices.. * that by 4
	
	load();
}

// we need to get the size of the square that will hover over the texture and set the tile texture
void TileMap::load()
{
	std::ifstream mapFile;
	mapFile.open(mapLoc);

	// ---- TILE ID VARIABLES ----
	int tileID[MAPSIZE];
	std::string temp;
	std::string data;
	int index = 0;

	// ---- Reading in a CSV file is the most tedious thing ever ----
	while (std::getline(mapFile, temp))
	{
		std::istringstream ss(temp);
		while (std::getline(ss, data, ','))
		{
			std::istringstream ss2(data);

			ss2 >> tileID[index];
			index++;
		}
	}

	int curTile = NULL;

	for (int row = 0; row < mapHeight; row++)
	{
		for (int column = 0; column < mapWidth; column++)
		{
			// ---- curTile is capturing the number that represents which tile to use ----
			curTile = tileID[column + (int)(row * mapWidth)]; // wow ok so they have an example on the SFML documentation page that uses a similar algorithm
			// I didnt understand it at all since it did not work, but i spent like 30 minutes drawing a grid and came up with that simple as hell eqn above (im slow sometimes) 

			// X and Y coordinates for textures are called U and V, not really sure why but yeah
			int coordU = (curTile % (int)(map->getSize().x / tileWidth)); // (index % mapWidth) = index of each tile in a grid, curTile is now an index, since it needs the location of the grid in TEXTURES not the WORLD
			int coordV = (curTile / (int)(map->getSize().x / tileWidth));

			// I vaguely understand what is going on below, but I'm getting too much of a head ache to follow along anymore, most of the equations below
			// is pulled together from this: https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php and https://gamedevelopment.tutsplus.com/tutorials/an-introduction-to-creating-a-tile-map-engine--gamedev-10900
			// save the location of the current tile
			sf::Vertex* quad = &mapVerts[(column + (int)(row * mapWidth)) * 4];

			// set the location in the map world (MAP COORDINATES)
			quad[0].position = sf::Vector2f(column * tileWidth, row * tileHeight);
			quad[1].position = sf::Vector2f((column + 1) * tileWidth, row * tileHeight);
			quad[2].position = sf::Vector2f((column + 1) * tileWidth, (row + 1) * tileHeight);
			quad[3].position = sf::Vector2f(column * tileWidth, (row + 1) * tileHeight);

			// set the location of the textures (TEXTURE COORDINATES)
			quad[0].texCoords = sf::Vector2f(coordU * tileWidth, coordV * tileHeight);
			quad[1].texCoords = sf::Vector2f((coordU + 1) * tileWidth, coordV * tileHeight);
			quad[2].texCoords = sf::Vector2f((coordU + 1) * tileWidth, (coordV + 1) * tileHeight);
			quad[3].texCoords = sf::Vector2f(coordU * tileWidth, (coordV + 1) * tileHeight);
		}
	}
}

 void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = map;

	target.draw(mapVerts, states);
}

