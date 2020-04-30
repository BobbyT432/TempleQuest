#include "animation.h"
#include <iostream>

// all animation does is set the size of a rectangle pretty much (it does NOT set the texture of the uvRect)
Animation::Animation(sf::Texture* texture, sf::Vector2f spriteCount_, float transitTime_)
{
	// ---- sf::Vector2f takes in two values, X and Y, this allows us to figure out how many sprites are in the picture ----
	spriteCount = spriteCount_;
	transitTime = transitTime_;
	deltaTime = 0;
	curSprite.x = 0;
	rowCount = 0;

	// ----Depending on how many sprites are in a row, divide by the PIXEL size that getSize returns ----
	uvRect.width = texture->getSize().x / spriteCount.x;  // getSize() returns the pixel count, for example if a picture is 100 pixels long and theres 5 sprites, dividing by 5 should give you 20 pixels long for each sprite
	uvRect.height = texture->getSize().y / spriteCount.y; 
}

void Animation::update(int row, float rowCount_, float deltaTime_)
{
	curSprite.y = row; // the row is which row of the sprite to act on, curSprite is an unsigned vector, so it only accepts positive values

	rowCount = rowCount_;

	deltaTime += deltaTime_; // delta time in this class will add the time it takes for each frame to pass, this gives us a better clock then just doing seconds because it is relative to the players time it takes to change frames
	// if we did a clock based off of actual time, it will be weird because it does not match the users frame rate
	// by doing delta time, its relative to the users frame rate

	// EXAMPLE: if one person has a computer that is extremely fast and it takes 0.01 second to cycle a frame, and the transition time is 5 seconds, it'll continually add up until its been 5 seconds to transfer to the next frame
	// if another person has a computer that is very slow, and it takes 5 seconds to cycle a frame, and the transition time is 5 seconds, it'll instantly change to the next frame every 5 seconds, it kind of matches the other person
	if (deltaTime >= transitTime) // once the total time (deltaTime) equals the transition time that is set, THEN go to the next sprite, (If the transition time is 3 seconds, wait 3 seconds then change)
	{
		deltaTime -= transitTime; // the reason why we don't just reset delta time back to zero is because deltaTime will NEVER perfectly match transitTime, (thats why we do deltaTime >= transitTime)
		// it adds up too fast and will eventually just go over transitTime, so subtract transitTime will make it balanced
		// Example: if transitTime was 3 seconds, and deltaTime added up to 3.6 seconds, reseting to zero will slow it down by .6 seconds, subtracting transitTime will start it off at 0.6 seconds and it'll do ACTUAL 3 seconds of transitTIme

		curSprite.x++; // change to the next sprite in the row

		if (curSprite.x >= rowCount_) // once it reaches the last sprite, loop back to the first one in the row
		{
			curSprite.x = 0;
		}
	}

	// ---- Changes the UV rect that goes over each individual sprite, which is then updated in the player class ----
	uvRect.left = curSprite.x * uvRect.width; // uvRect.left is the LEFT side of the sprite, curSprite.x = 0 in the first frame, so 0 * width of each SPRITE will give you the left side of the sprite, 1 * width of the example sprite above will take you 20 pixels to the right, which is the left of the next sprite
	uvRect.top = curSprite.y * uvRect.height; // uvRect.top is the TOP side of the sprite, if you're only doing the first row, it'll be 0 the entire time
	// also uvRect already knows the size of each capture rectangle that needs to go over every sprite, uvRect.width and uvRect.height are already initialized in the constructor
}

void Animation::setStatic(int row, float index)
{
	curSprite.y = row;
	curSprite.x = index;

	uvRect.left = curSprite.x * uvRect.width;
	uvRect.top = curSprite.y * uvRect.height;
}
