#ifndef ANIMATION
#define ANIMATION

#include <SFML/Graphics.hpp>

class Animation
{
private:
	// ---- Animation properties ----
	sf::Vector2f spriteCount;
	sf::Vector2u curSprite; // current sprite
	float rowCount; // seperate variable to split sprites up into rows

	// ---- Variables that smooth the animation ----
	float deltaTime; // time since last animation cycle
	float transitTime; // how long till the animation transitions
public:
	
	// ---- Takes in the texture, X and Y of how many sprites there are, and how much time to wait till passing onto the next animation ----
	Animation(sf::Texture* texture, sf::Vector2f spriteCount_, float transitTime_);
	//~Animation();

	// ---- Needs to be public, this is what changes the players texture ----
	sf::IntRect uvRect; // uv Rectangle

	// ---- This has to be always running, thats why it will update each frame ----
	void update(int row, float rowCount_, float deltaTime_);
	void setStatic(int row, float index);
};
#endif