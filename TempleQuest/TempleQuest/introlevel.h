#ifndef INTROLVL
#define INTROLVL

#include "levelmanager.h"
#include "elderjoh.h"
#include "player.h"
#include "skeleman.h"

class IntroLevel : public LevelManager
{
private:
	Player* player;
	ElderJoh* yongmin;
	
	// ---- Event variables ----
	sf::Font font;
	sf::Text text;
	sf::Text name;
	sf::Text tut;
	std::vector<sf::Text> convo;
	int index; // keeping track of dialogue
	sf::Clock convoClock;
	sf::Clock levelClock;

	sf::RectangleShape *convoBox;
	sf::Texture convoTex;

	int transitState;
public:
	IntroLevel(sf::RenderWindow& window_);
	unsigned int update(float deltaTime);
	void playEvent();
	void setEvent();
	bool checkTransit();
	void draw();
};
#endif

