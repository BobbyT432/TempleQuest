#ifndef GAME
#define GAME

// this will not stay in the final release, use this for debugging purposes to mess with the size of the window
#define WIDTH 1920
#define HEIGHT 1080
#define TITLE "Temple Quest"


// keep most includes here, if we have too many includes in seperate areas, compile time will be bad 
// also cool lil trick if you do 'CTRL + .' over a function decleration, it auto makes a definition in its .cpp equivalent
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "state.h"

class Game
{
private:
	sf::RenderWindow *window; // its a pointer so windows can be dynamically created once a new object is made
	sf::Event event;

	// for delta time
	sf::Clock clock;
	float deltaTime; // delta time is the elapsed time it took for one frame to cycle, this will be useful for that problem where faster computers run the program faster
	// for FPS
	sf::Clock fpsClock;
	float frame;
	float FPS;
public:
	Game();
	~Game();
	// init functions
	void initWindow();
	// main game loop
	void run();
	// SFML functions
	void eventHandler();
	// Utilities (maybe transfer to a new class idk)
	void updateDt();
	void showFPS();
};

#endif