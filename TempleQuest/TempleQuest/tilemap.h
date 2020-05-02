#ifndef TILEMAP
#define TILEMAP

#define MAPSIZE 10000

#include <SFML/Graphics.hpp> // for now
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include <sstream>
#include <SFML/Audio.hpp>


class TileMap : public sf::Drawable, public sf::Transformable // we need these SFML classes to override the draw class
{
private:
	// ---- Tile attributes ----
	float tileWidth;
	float tileHeight;
	float mapWidth;
	float mapHeight;
	sf::Texture *map;
	sf::Vector2f tileCount;
	sf::VertexArray mapVerts; // vertex array because we can write directly to a buffer which THEN displays the whole buffer at once 

	// ---- Map attributes ----
	std::string mapLoc;
	// ---- Debugging purposes ----
	sf::Text text;
	sf::Font font;
public:
	TileMap(std::string texLoc, std::string mapLoc_, sf::Vector2f tileSize, float mapWidth_, float mapHeight_);
	
	void load();

	// ---- SFML functions ----
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif