#include "level02.h"

Level02::Level02(sf::RenderWindow& window_)
{
	window = &window_;

	col = new Collision("levels/collisions/test_C.csv", 2500); // area of tilemap
	zero = new TileMap("textures/boca_final.png", "levels/final_B.csv", sf::Vector2f(32, 32), 50, 50);
	//one = new TileMap("textures/boca_front.png", "levels/bocabowa_F.csv", sf::Vector2f(32, 32), 100, 100);

	// ---- Create all entities ----
	const int skelemanAmt = 5;
	
	player = new Player;
	huskyGanon = new Ganon;

	// ---- When the player walks in, he's facing forward ----
	player->getEnt()->setPosition(465.39, 1360.92);
	player->setDir(FORWARD);
	huskyGanon->getEnt()->setPosition(383.498, 330.398);
	huskyGanon->setDir(DOWN);

	// ---- Set collision for any entities in the scene ----
	player->setCol(*col);
	entGroup.emplace_front(player);
	huskyGanon->setCol(*col);
	entGroup.emplace_front(huskyGanon);

	// ---- Do this for AI ----
	sf::Vector2f skelePos[skelemanAmt] = { sf::Vector2f(371.791, 1135.91), sf::Vector2f(324.998, 471.697),
										   sf::Vector2f(308.791, 1071.11), sf::Vector2f(435.698, 471.697),
										   sf::Vector2f(403.29, 958.609),};

	for (int count = 0; count < skelemanAmt; count++)
	{
		Skeleman* skele = new Skeleman;
		skele->setCol(*col);
		skele->setGroup(entGroup);
		skele->getEnt()->setPosition(skelePos[count]);
		entGroup.emplace_front(skele);
	}

	// ---- Acknowledge the entity groups by all entities ----
	huskyGanon->setGroup(entGroup);
	player->setGroup(entGroup);

	// ---- Transition variables ----
	transitPos1 = sf::Vector2f(279.999, 926.208);
	transitPos2 = sf::Vector2f(1103.51, 225.099);
	transit = 1;
}

unsigned int Level02::update(float deltaTime)
{
	// ---- Spawn entities ----
	for (std::list<Entity*>::iterator it = entGroup.begin(); it != entGroup.end(); ++it)
	{
		Entity* ent;
		ent = *it;
		if (ent->isPlayer() == 0)
		{
			ent->update(deltaTime);
			ent->setTarget(player->getPos());
		}
	}

	// ---- Update player ----
	transit = player->update(deltaTime);

	// ---- Check if transition is needed ----
	checkTransit();

	// ---- Draw everything to the screen ----
	draw();

	if (transit == 2) { return 0; } // if the player died, return 0
	if (huskyGanon->getHP() <= 0) { return 3; } // the player has WON!

	return 2;
}

void Level02::checkTransit()
{
	// ---- Checks to see if the player is in a transition block (changing levels / or setting position) ----
	int offset = 10;

	// ---- Inefficent way but oh well ----
	if ((player->getPos().x >= transitPos1.x - offset) && (player->getPos().x <= transitPos1.x + offset))
	{
		if ((player->getPos().y >= transitPos1.y - offset) && (player->getPos().y <= transitPos1.y + offset))
		{
			player->getEnt()->setPosition(sf::Vector2f(1103.51, 924.408));
		}
	}
	if ((player->getPos().x >= transitPos2.x - offset) && (player->getPos().x <= transitPos2.x + offset))
	{
		if ((player->getPos().y >= transitPos2.y - offset) && (player->getPos().y <= transitPos2.y + offset))
		{
			player->getEnt()->setPosition(sf::Vector2f(383.498, 580.599));
		}
	}
}

void Level02::draw()
{
	Entity* ent;

	// ---- Draw tilemaps ----
	window->draw(*zero);

	// ---- Draw entities ----
	for (std::list<Entity*>::iterator it = entGroup.begin(); it != entGroup.end(); ++it)
	{
		ent = *it;
		ent->draw(*window);
	}

	//window->draw(*one);
}
