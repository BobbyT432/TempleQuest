#ifndef STATE
#define STATE


// this will not stay in the final release, use this for debugging purposes to mess with the size of the window
#define WIDTH 1920
#define HEIGHT 1080
#define TITLE "Temple Quest"

//----- keep most includes here, if we have too many includes in seperate areas, compile time will be bad -----
#include <map>
#include "level01.h"
#include "level02.h"
#include "introlevel.h"

// ok so states will tell us what state the game is in, read this: https://gameprogrammingpatterns.com/state.html
// Main Menu is a state, is the game running is a state, pause menu is a state, etc etc
// I'm only seeing how other people are making games and mostly everyone does this method

// ----- an enum makes it easier to understand what state to switch too, (enums just assign number values to text) -----
enum State_
{
	STATE_INTRO,
	STATE_GAME,
	STATE_DEAD,
	STATE_WON,
};

// ----- class interface for each state -----
class State
{
protected:
	
public:
	//State();
	virtual void run(sf::RenderWindow *window) = 0;
	virtual ~State() = default; // virtual destructor cus we will be inheriting this class
};

// ----- STATES -----
// The intro state will only be played when the game starts
class IntroState : public State
{
public:
	void run(sf::RenderWindow* window);
};

// The game state will only be in action when the player should have control (the entire game except cutscenes, etc)
class GameState : public State
{
public:
	void run(sf::RenderWindow* window);
};

class deadState : public State
{
public:
	void run(sf::RenderWindow* window);
};

class wonState : public State
{
private:
	sf::Clock winTimer;
public:
	void run(sf::RenderWindow* window);
};

#endif