#include "game.h"
#include <sstream> // to be moved

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete window;
}

// ---- This is where the main window is created ----
void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Fullscreen);
	window->setFramerateLimit(120);
	window->setMouseCursorVisible(false);
	//window->setVerticalSyncEnabled(true);
}

// ---- Our main game L O O P ----
void Game::run()
{
	// ---- Our main player object and game state ----
	StateManager state;

	Level01 lvl01(*window); // idea: create a queue / stack / etc that holds all levels, if transit = 1, then pop the last level out and go to the next
	Level02 lvl02(*window);
	IntroLevel introlvl(*window);

	unsigned int transit = 1; // 0 = dead, 1 = continue, 2 = transition

	// ---- What state the game starts in ----
	state.playState(STATE_GAME, window);

	// this is our main game loop, each loop is ONE frame
	// Possible problem: Depending on how fast the persons computer is, is how fast the game will run (which is bad)
	// Possible solution: Lock the loop to 60 FPS

	while (window->isOpen())
	{
	
		eventHandler();

		// ---- Utilities ----
		updateDt();
		showFPS();

			window->clear(sf::Color(168,182,189));
			if (transit != 3 && transit != 0)
			{
			if (transit == 1) { transit = introlvl.update(deltaTime); }
			if (transit == 4) { transit = lvl01.update(deltaTime); }
			if (transit == 2) { transit = lvl02.update(deltaTime); }
			window->display();
			}
		if (transit == 0) { state.playState(STATE_DEAD, window); }
		if (transit == 3) { state.playState(STATE_WON, window); }
	}
}

// ---- Handle all WINDOW events here (notifies if something has happened, as opposed to generic input which constantly checks if somethings happened) ----
void Game::eventHandler() 
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

// ---- Deltatime will help solve the bug where faster computers run the game faster ----
void Game::updateDt() 
{
	deltaTime = clock.restart().asSeconds(); // updates deltaTime with time it took to go a full frame
	//std::cout << deltaTime << std::endl;
}

// ---- Adds up frames each time the main loop cycles, once a second has passed display that frame count ----
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
