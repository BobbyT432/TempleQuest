#include "level01.h"

Level01::Level01(sf::RenderWindow &window_)
{
	window = &window_;

	col = new Collision("levels/collisions/01_C.csv", 900);
	back = new TileMap("textures/tilemap-Sheet.png", "levels/01_B.csv", sf::Vector2f(32, 32), 30, 30);
	ground = new TileMap("textures/tilemap-Sheet.png", "levels/01_F.csv", sf::Vector2f(32, 32), 30, 30);

	player = new Player;
	skeleman = new Skeleman;

	// ---- Set collision for any entities in the scene ----
	player->setCol(*col);
	skeleman->setCol(*col);
	// ---- Initialize entities on the level and put them in the group list ----
}

void Level01::update(float deltaTime)
{
	skeleman->update(deltaTime);
	skeleman->setTarget(player->getPos());
	player->update(deltaTime);
	draw();
}

void Level01::draw()
{
	// ---- Draw tilemaps ----
	window->draw(*back);
	window->draw(*ground);

	// ---- Draw entities ----
	player->draw(*window);
	skeleman->draw(*window);
}



