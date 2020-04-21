#include "game.h"

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete window;
}

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	window->setFramerateLimit(120);
}

void Game::run()
{
	// this is our main game loop, each loop is ONE frame
	// Possible problem: Depending on how fast the persons computer is, is how fast the game will run (which is bad)
	// Possible solution: Lock the loop to 60 FPS
	while (window->isOpen())
	{
		eventHandler();

		updateDt(); 
		showFPS();
		window->clear();
		window->display();
	}
}

void Game::eventHandler() // handle all WINDOW events here, the event handler will notify if something has happened, while generic input CONSTANTLY checks if somethings happened
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

void Game::updateDt() // updates deltaTime with time it took to go a full frame
{
	deltaTime = clock.restart().asSeconds();
	//std::cout << deltaTime << std::endl;
}

void Game::showFPS()
{
	frame++;
	if (fpsClock.getElapsedTime().asSeconds() >= 1.00)
	{
		FPS = frame;
		fpsClock.restart();
		frame = 0;
		std::cout << "FPS: " << FPS << std::endl;
	}
	
}
