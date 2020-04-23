#include "game.h"

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
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	window->setFramerateLimit(120);
}

// ---- Our main game L O O P ----
void Game::run()
{
	Player test; // TO BE REMOVED
	InputHandler inputHandler;
	StateManager state;

	// this is our main game loop, each loop is ONE frame
	// Possible problem: Depending on how fast the persons computer is, is how fast the game will run (which is bad)
	// Possible solution: Lock the loop to 60 FPS
	while (window->isOpen())
	{
		eventHandler();

		updateDt(); 
		showFPS();

		state.playState(STATE_GAME);
		inputHandler.assignCommand(test);
		window->clear();
		test.draw(*window);
		window->display();
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
