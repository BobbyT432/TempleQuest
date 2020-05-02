#ifndef STATEMANA
#define STATEMANA

#include "state.h"

// ---- Handle all states EASILY with this ----
class StateManager
{
private:
	std::map<State_, State*> states; // an array of states that can be used
	State_ currentState;
	State_ nextState;
public:
	StateManager();
	void playState(State_ state, sf::RenderWindow* window);
};

#endif