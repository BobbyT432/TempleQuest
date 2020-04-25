#include "tilemap.h"
TileMap::TileMap(const std::string& tileSet, float tileWidth_, float tileHeight_, float mapWidth_, float mapHeight_, int level[])
{
	// ---- Whenever a new map with a NEW tile set is created, it'll read it in here, however we should stick to one file ----
	map = new sf::Texture;
	map->loadFromFile(tileSet);
	tileWidth = tileWidth_;
	tileHeight = tileHeight_;
	mapWidth = mapWidth_;
	mapHeight = mapHeight_;
	tileCount.x = mapWidth / tileWidth; // how many tiles in x or y direction are needed
	tileCount.y = mapHeight / tileHeight;
	mapVerts.setPrimitiveType(sf::Quads);

	// ---- Debugging purposes ----
	font.loadFromFile("fonts/ReturnofGanon.ttf");
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setPosition(200, 200);
	text.setString("Bobby is the best programmer");

	draw(level);
}

// ---- This will be updated in the main game loop ----
void TileMap::update(sf::RenderWindow &window)
{
	window.draw(text);
}

void TileMap::draw(int level[])
{
	int curTile = NULL;

	for (int row = 0; row < tileCount.y; row++)
	{
		for (int column = 0; column < tileCount.y; column++)
		{
			//curTile = level[(row + column) * tileWidth];
		}
	}
}
