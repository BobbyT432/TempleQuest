#ifndef LVL2
#define LVL2

#include "levelmanager.h"
#include "player.h"
#include "skeleman.h"
#include "ganon.h"

class Level02 : public LevelManager
{
private:
	Player* player;
	Ganon* huskyGanon;

	// ---- I understand this is inefficent to do 2 seperate variables instead of some sort of vector, but i have 8 hours left till this is due ----
	sf::Vector2f transitPos1; 
	sf::Vector2f transitPos2;
public:
	Level02(sf::RenderWindow& window_);
	unsigned int update(float deltaTime);
	void checkTransit();
	//void setPlayer(Player& player_); // only for level 2 and above
	void draw();
};
#endif