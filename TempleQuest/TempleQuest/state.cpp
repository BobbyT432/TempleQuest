#include "state.h"

void IntroState::run(sf::RenderWindow* window)
{

}

void GameState::run(sf::RenderWindow* window)
{

}

void deadState::run(sf::RenderWindow* window)
{
	// ---- Game over screen ----
	sf::RectangleShape deathScreen(sf::Vector2f(1920, 1080));
	sf::FloatRect deathRect = deathScreen.getLocalBounds();
	deathScreen.setOrigin(deathRect.left + deathRect.width / 2.0f,
		deathRect.top + deathRect.height / 2.0f);
	deathScreen.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f));

	// ---- Game over screen texture ----
	sf::Texture deathTex;
	deathTex.loadFromFile("textures/gameover.png");
	deathScreen.setTexture(&deathTex);

	// ---- Set the view to the game over screen ----
	sf::View deathView(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f), sf::Vector2f(1920, 1080));
	window->setView(deathView);

	float fade = 0.0f; // fade the screen in

	while(fade < 255)
	{
	//	if (fade >= 100) { window->clear(); }
		
		fade += 0.5;
		deathScreen.setFillColor(sf::Color(255,255,255, fade));
		window->draw(deathScreen);
		window->display();
	 
	}
}

void wonState::run(sf::RenderWindow* window)
{
	if (winTimer.getElapsedTime().asSeconds() >= 10) { winTimer.restart(); }
	if (winTimer.getElapsedTime().asSeconds() >= 3) { window->close(); }
	// ---- Game over screen ----
	sf::RectangleShape winScreen(sf::Vector2f(1920, 1080));
	sf::FloatRect winRect = winScreen.getLocalBounds();
	winScreen.setOrigin(winRect.left + winRect.width / 2.0f,
		winRect.top + winRect.height / 2.0f);
	winScreen.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f));

	// ---- Game over screen texture ----
	sf::Texture winTex;
	winTex.loadFromFile("textures/winscreen.png");
	winScreen.setTexture(&winTex);

	// ---- Set the view to the game over screen ----
	sf::View winView(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f), sf::Vector2f(1920, 1080));
	window->setView(winView);

	float fade = 0.0f; // fade the screen in

	while (fade < 255)
	{
		//	if (fade >= 100) { window->clear(); }

		fade += 0.5;
		winScreen.setFillColor(sf::Color(255, 255, 255, fade));
		window->draw(winScreen);
		window->display();

	}
}
