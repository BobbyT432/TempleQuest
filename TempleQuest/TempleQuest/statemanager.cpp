#include "statemanager.h"

// ---- Initialize the array with the enum as the indexer and the class object as the value ----
StateManager::StateManager()
{
	
	states.emplace(STATE_INTRO, new IntroState);
	states.emplace(STATE_GAME, new GameState);
}

// ---- Matches the state indexer to the correct enum and executes that values run command ----
void StateManager::playState(State_ state)
{
	states[state]->run();
}