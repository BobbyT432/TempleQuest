#include "introlevel.h"

IntroLevel::IntroLevel(sf::RenderWindow& window_)
{
	window = &window_;

	col = new Collision("levels/collisions/intro_C.csv", 400); // area of tilemap
	zero = new TileMap("textures/intro_B.png", "levels/intro_B.csv", sf::Vector2f(32, 32), 20, 20);
	
	// ---- Create all entities ----
	player = new Player;
	yongmin = new ElderJoh;

	player->getEnt()->setPosition(303.399, 165.7);
	player->setDir(RIGHT);
	yongmin->getEnt()->setPosition(490, 170);
	// ---- Set collision for player in the scene ----
	player->setCol(*col);
	entGroup.emplace_front(player); // enter him in the global entity container (keeps track of the entities in the map)
	yongmin->setCol(*col);
	entGroup.emplace_front(yongmin);

	// ---- Acknowledge the entity groups by the player ----
	player->setGroup(entGroup);
	yongmin->setGroup(entGroup);

	// ---- Transition variables ----
	transitState = 0;

	// ---- Event variables ----
	font.loadFromFile("fonts/ReturnofGanon.ttf");

	convoBox = new sf::RectangleShape(sf::Vector2f(200, 75));
	convoBox->setPosition(sf::Vector2f(303.399 - 82, 85));
	convoTex.loadFromFile("textures/dialoguebox.png");
	convoBox->setTexture(&convoTex);

	setEvent();
	name.setCharacterSize(40);
	name.setFillColor(sf::Color(232, 44, 75));
	name.setFont(font);
	name.setPosition(308, 90);
	name.setStyle(sf::Text::Bold);
	name.scale(sf::Vector2f(0.2f, 0.2f));
	name.setString("Elder Joh");

	tut.setCharacterSize(40);
	tut.setFillColor(sf::Color(31, 131, 237));
	tut.setFont(font);
	tut.setPosition(288, 145);
	tut.setStyle(sf::Text::Bold);
	tut.scale(sf::Vector2f(0.2f, 0.2f));
	tut.setString("Press Enter to continue");
}

unsigned int IntroLevel::update(float deltaTime)
{
	// ---- Update entities ----
	player->update(deltaTime);
	yongmin->update(deltaTime);

	// ---- Draw everything to the screen ----
	draw();

	if (levelClock.getElapsedTime().asSeconds() > 3.5) { playEvent(); window->draw(name); window->draw(tut); }
	
	// ---- Checks to see if the player needs to transition ----
	if (checkTransit()) { return 4; } // transition to next level

	// ---- Continue on ----
	return 1;
}

void IntroLevel::playEvent()
{
	if (convoClock.getElapsedTime().asSeconds() >= 2)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && index < convo.size() - 1)
		{
			convoClock.restart();

			index++;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && index == (convo.size() - 1))
		{
			transitState = 1;
		}
	}
	window->draw(*convoBox);
	window->draw(convo[index]);
}

void IntroLevel::setEvent()
{
	
	text.setCharacterSize(60);
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setPosition(251, 115);
	text.scale(sf::Vector2f(0.2f, 0.2f));
	text.setString("Listen closely young Butch..");

	convo.push_back(text);

	text.setPosition(253, 108);
	text.setString("The island of Bocabowa has been\n plagued by a dark force..");
	convo.push_back(text);

	text.setPosition(253, 100);
	text.setString("Harry Husk has dispersed his minions\n among the land, preventing\n anyone from traveling..");
	convo.push_back(text);

	text.setPosition(253, 95);
	text.setString("He lays rest atop Mount Brendle at\n the Temple of Rutger, he must be\n stopped before he becomes more\n powerful.. ");
	convo.push_back(text);
	
	text.setPosition(254, 100);
	text.setString("The elders have chosen you..\n I must train you before our\n time is too late..");
	convo.push_back(text);

	text.setPosition(253, 105);
	text.setString("You must learn to use your blade..\n it will guide your strength..");
	convo.push_back(text);

	text.setPosition(253, 95);
	text.setFillColor(sf::Color(107, 194, 108));
	text.setString("Press LMB to swing your sword,\n W A S D to move around, you may\n change keybindings anytime in\n keybindings.txt..");
	convo.push_back(text);

	text.setPosition(253, 95);
	text.setFillColor(sf::Color::White);
	text.setString("You're ready.. go now!\n Harry Husk only gets stronger!\n Find Mount Brendle and put an end\n to this unrest!");
	convo.push_back(text);
}

bool IntroLevel::checkTransit()
{
	if (transitState == 1) { return 1; }
	return 0;
}

void IntroLevel::draw()
{
	Entity* ent;

	// ---- Draw tilemaps ----
	window->draw(*zero); // layer zero (draw before the player)

	// ---- Draw entities ----
	for (std::list<Entity*>::iterator it = entGroup.begin(); it != entGroup.end(); ++it)
	{
		ent = *it;
		ent->draw(*window);
	}
}



