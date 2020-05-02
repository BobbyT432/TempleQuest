#ifndef GAME
#define GAME

// also cool lil trick if you do 'CTRL + .' over a function decleration, it auto makes a definition in its .cpp equivalent
#include "statemanager.h"

class Game
{
private:
	sf::RenderWindow *window; // its a pointer so windows can be dynamically created once a new object is made
	sf::Event event;

	// ---- Delta time ----
	sf::Clock clock;
	float deltaTime; // delta time is the elapsed time it took for one frame to cycle, this will be useful for that problem where faster computers run the program faster
	
	// ---- FPS Counter ----
	sf::Clock fpsClock;
	float frame;
	float FPS;
public:
	Game();
	~Game();

	// ---- Init functions ----
	void initWindow();

	// ---- Main game loop ----
	void run();

	// ---- SFML functions ----
	void eventHandler();

	// ---- Utilities ----
	void updateDt();
	void showFPS();
};

#endif