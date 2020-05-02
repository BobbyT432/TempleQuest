#include "statemanager.h"

// ---- Initialize the array with the enum as the indexer and the class object as the value ----
StateManager::StateManager()
{
	states.emplace(STATE_INTRO, new IntroState);
	states.emplace(STATE_GAME, new GameState);
	states.emplace(STATE_DEAD, new deadState);
	states.emplace(STATE_WON, new wonState);
}

// ---- Matches the state indexer to the correct enum and executes that values run command ----
void StateManager::playState(State_ state, sf::RenderWindow *window)
{
	states[state]->run(window);
}