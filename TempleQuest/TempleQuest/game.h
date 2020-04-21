#ifndef GAME
#define GAME

// this will not stay in the final release, use this for debugging purposes to mess with the size of the window
#define WIDTH 1920
#define HEIGHT 1080
#define TITLE "Temple Quest"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>



// keep most includes here, if we have too many includes in seperate areas, compile time will be bad 
// also cool lil trick if you do 'CTRL + .' over a function decleration, it auto makes a definition in its .cpp equivalent
class Game
{
private:
	sf::RenderWindow *window; // its a pointer so windows can be dynamically created once a new object is made
	sf::Event event;
public:
	Game();
	~Game();
	// init functions
	void initWindow();
	// main game loop
	void run();
	// SFML functions
	void eventHandler();
};

#endif