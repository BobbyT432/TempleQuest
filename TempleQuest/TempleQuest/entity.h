#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// ---- The base class for which every entity in the game will be derived from ----
class Entity 
{
protected:
	// ---- Entity attributes ----
	sf::Vector2f pos; // entity position
	bool collider; // is this entity collidable?
	bool controllable; // can this entity be controlled by the player?
	float velocity;
	float hp;

	// ---- What will be displayed of the entity ----
	sf::RectangleShape* entity; // This is the ACTUAL entity, the thing that will be displayed to the screen
	sf::Texture* entTexture; // the entities texture
public:
	
	Entity();
	virtual ~Entity() = default;

	// ---- Entity info ----
	sf::Vector2f getPos();
	bool isPlayer(); // a flag that says if this entity is a player controlled entity
	virtual float getVelo();

	// ---- To be overrided ----
	//virtual void onInteract(Entity* ent); // this function will perform something when another entity interacts with this objects entity

	// ---- Return the entities figure (what needs to be rendered) ----
	virtual sf::RectangleShape* getEnt() = 0;

	// ---- SFML Properties ----
	virtual void draw(sf::RenderWindow& window);
};
#endif