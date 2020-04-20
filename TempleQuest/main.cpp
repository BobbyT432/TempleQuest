#include <SFML/Graphics.hpp>

// this will not stay in the final release, use this for debugging purposes to mess with the size of the window
#define WIDTH 1920
#define HEIGHT 1080
#define TITLE "Temple Quest"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);

	// this is our main game loop, each loop is ONE frame
	// Possible problem: Depending on how fast the persons computer is, is how fast the game will run (which is bad)
	// Possible solution: Lock the loop to 60 FPS
	while (window.isOpen()) 
	{
		
		window.clear();
		window.display();
	}
	return 0;
}
