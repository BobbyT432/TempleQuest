#include "level01.h"

Level01::Level01(sf::RenderWindow &window_)
{
	window = &window_;

	col = new Collision("levels/collisions/boca_C.csv", 10000); // area of tilemap
	zero = new TileMap("textures/boca_back.png", "levels/bocabowa_B.csv", sf::Vector2f(32, 32), 100, 100);
	one = new TileMap("textures/boca_front.png", "levels/bocabowa_F.csv", sf::Vector2f(32, 32), 100, 100);
   
	// ---- Create all entities ----
	const int skelemanAmt = 30;

	player = new Player;

	player->getEnt()->setPosition(607, 2535);

	// ---- Set collision for player in the scene ----
	player->setCol(*col);
	entGroup.emplace_front(player); // enter him in the global entity container (keeps track of the entities in the map)

	// ---- All enemy spawn points ----
	sf::Vector2f skelePos[skelemanAmt] = { sf::Vector2f(715, 1244), sf::Vector2f(2095, 1141),
										   sf::Vector2f(670, 1153), sf::Vector2f(2168, 1100),
										   sf::Vector2f(857, 1610), sf::Vector2f(2329, 1082),
										   sf::Vector2f(812, 1661), sf::Vector2f(2026, 864),
										   sf::Vector2f(1094, 1598), sf::Vector2f(2159, 775),
										   sf::Vector2f(1644, 1580), sf::Vector2f(2521, 919),
										   sf::Vector2f(2033, 1678), sf::Vector2f(2568, 998),
										   sf::Vector2f(2217, 1729), sf::Vector2f(2687, 796),
										   sf::Vector2f(2094, 1936), sf::Vector2f(2506, 825),
										   sf::Vector2f(1814, 1972), sf::Vector2f(2431, 784),
										   sf::Vector2f(1997, 2081), sf::Vector2f(1703, 674),
										   sf::Vector2f(2046, 2238), sf::Vector2f(1294, 804), 
										   sf::Vector2f(2106, 2509), sf::Vector2f(1344, 851),
										   sf::Vector2f(1679, 1360), sf::Vector2f(1525, 856),
										   sf::Vector2f(1804, 1337), sf::Vector2f(1525, 850), };
	
	// ---- Create the enemies and do all the properties same as I did to the player ----
	for (int count = 0; count < skelemanAmt; count++)
	{
		Skeleman* skele = new Skeleman;
		skele->setCol(*col);
		skele->setGroup(entGroup);
		 skele->getEnt()->setPosition(skelePos[count]);
		entGroup.emplace_front(skele);
	}

	// ---- Acknowledge the entity groups by the player ----
	player->setGroup(entGroup);

	// ---- Transition variables ----
	transitPos = sf::Vector2f(1342.62, 716.713);
	transit = 1;
}

unsigned int Level01::update(float deltaTime)
{
	// ---- Spawn entities ----
	for (std::list<Entity*>::iterator it = entGroup.begin(); it != entGroup.end(); ++it)
	{
		Entity* ent;
		ent = *it;
		if (ent->isPlayer() == 0)
		{
			ent->update(deltaTime);
			ent->setTarget(player->getPos()); // continually sets the target to the player
		}
	}

	// ---- Update player ----
	transit = player->update(deltaTime);

	// ---- Draw everything to the screen ----
	draw();

	// ---- Checks to see if the player needs to transition ----
	if (checkTransit()) { return 2; } // transition to next level
	if (transit == 0) { return 0; } // if the player died, return 0

	// ---- Continue on ----
	return 4;
}

bool Level01::checkTransit()
{
	// ---- Checks to see if the player is in a transition block ----
	int offset = 10;
	if ((player->getPos().x >= transitPos.x - offset) && (player->getPos().x <= transitPos.x + offset))
	{
		if ((player->getPos().y >= transitPos.y - offset) && (player->getPos().y <= transitPos.y + offset))
		{
			return 1;
		}
	}
	return 0;
}

void Level01::draw()
{
	Entity* ent;

	// ---- Draw tilemaps ----
	window->draw(*zero); // layer zero (draw before the player)

	// ---- Draw entities ----
	for (std::list<Entity*>::iterator it = entGroup.begin(); it != entGroup.end(); ++it)
	{
		ent = *it;
		ent->draw(*window);
	}
	
	// ---- Draw layer one ----
	window->draw(*one); // (draw after the player)
}



