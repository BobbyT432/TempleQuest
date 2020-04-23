#ifndef ANIMATION
#define ANIMATION

#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Vector2f spriteCount;
	sf::Vector2u curSprite; // current sprite

	float deltaTime; // time since last animation cycle
	float transitTime; // how long till the animation transitions
public:
	
	Animation(sf::Texture* texture, sf::Vector2f spriteCount_, float transitTime_);
	//~Animation();

	sf::IntRect uvRect; // uv Rectangle

	void update(int row, float deltaTime_);
};
#endif