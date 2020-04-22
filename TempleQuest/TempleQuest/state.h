#ifndef STATE
#define STATE

//----- keep most includes here, if we have too many includes in seperate areas, compile time will be bad -----
#include "player.h"
#include "inputhandle.h"
#include <map>


// ok so states will tell us what state the game is in
// Main Menu is a state, is the game running is a state, pause menu is a state, etc etc
// I'm only seeing how other people are making games and mostly everyone does this method

// ----- an enum makes it easier to understand what state to switch too, (enums just assign number values to text) -----
enum State_
{
	STATE_INTRO,
	STATE_GAME,
	STATE_PAUSE,
	STATE_CUTSCENE,
};

// ----- class interface for each state -----
class State
{
protected:
	
public:
	//State();
	virtual void run() = 0;
	virtual ~State() = default; // virtual destructor cus we will be inheriting this class
};

// ----- STATES -----
// The intro state will only be played when the game starts
class IntroState : public State
{
public:
	void run();
};

// The game state will only be in action when the player should have control (the entire game except cutscenes, etc)
class GameState : public State
{
public:
	void run();
};




#endif