#ifndef STATE
#define STATE

// ok so states will tell us what state the game is in
// Main Menu is a state, is the game running is a state, pause menu is a state, etc etc
// I'm only seeing how other people are making games and mostly everyone does this method
class State
{
private:

public:
	State();
	virtual ~State(); // virtual destructor cus we will be inheriting this class
	
	// State is an abstract class, so therefore we need us some pure virtuals
	// you can't create a direct object of this class, but you can of its derived classes (as long as you override the functions below)
	virtual void update() = 0;
	virtual void render() = 0; 
};
#endif