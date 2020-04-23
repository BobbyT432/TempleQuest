#include "animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2f spriteCount_, float transitTime_)
{
	spriteCount = spriteCount_;
	transitTime = transitTime_;
	deltaTime = 0;
	curSprite.x = 0;

	uvRect.width = texture->getSize().x / spriteCount.x; // depending on how many sprites are in a row, divide by the PIXEL size that get size returns
	uvRect.height = texture->getSize().y / spriteCount.y;
}



void Animation::update(int row, float deltaTime_)
{
	curSprite.y = row;
	deltaTime += deltaTime_;

	if (deltaTime >= transitTime)
	{
		deltaTime -= transitTime;

		curSprite.x++;

		if (curSprite.x >= spriteCount.x)
		{
			curSprite.x = 0;
		}
	}
	uvRect.left = curSprite.x * uvRect.width;
	uvRect.top = curSprite.y * uvRect.height;
}
