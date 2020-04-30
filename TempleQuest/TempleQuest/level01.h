#ifndef LVL1
#define LVL1

#include "levelmanager.h"
#include "player.h"
#include "skeleman.h"

class Level01 : public LevelManager
{
private:
	Player *player;
	Skeleman* skeleman;
public:
	Level01(sf::RenderWindow& window_);
	void update(float deltaTime);
	void draw();
};
#endif