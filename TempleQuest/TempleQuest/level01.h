#ifndef LVL1
#define LVL1

#include "levelmanager.h"
#include "player.h"
#include "skeleman.h"

class Level01 : public LevelManager
{
private:
	Player *player;
	sf::Vector2f transitPos; // where the player has to be for it to transition levels
public:
	Level01(sf::RenderWindow& window_);
	unsigned int update(float deltaTime);
	bool checkTransit();
	void draw();
};
#endif