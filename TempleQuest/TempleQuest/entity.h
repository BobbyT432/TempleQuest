#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Entity 
{
protected:
	sf::Vector2f pos; // entity position
	bool collider; // is this entity collidable?
	bool player;

	sf::RectangleShape* playerBod; // THIS WILL BE REMOVED
	float velocity;
public:
	
	Entity();
	//virtual ~Entity();

	// entity info
	sf::Vector2f getPos();
	bool isPlayer(); // a flag that says if this entity is a player controlled entity

	// to be overrided
	//virtual void onInteract(Entity* ent); // this function will perform something when another entity interacts with this objects entity

	// TO BE REMOVED, TESTING PURPOSES
	virtual sf::RectangleShape* getBod() = 0;

	virtual float getVelo();
};
#endif