#ifndef TILEMAP
#define TILEMAP

#include <SFML/Graphics.hpp> // for now

class TileMap
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
	// ---- Debugging purposes ----
	sf::Text text;
	sf::Font font;
public:
	TileMap(const std::string& tileSet, float tileWidth_, float tileHeight_, float mapWidth_, float mapHeight_, int level[]);
	void update(sf::RenderWindow &window);
	void draw(int level[]);
};
#endif