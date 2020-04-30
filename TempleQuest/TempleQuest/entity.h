#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "animation.h"
#include "collision.h"


// ---- Used to tell which idle animation to use, when hes done walking right, idle right, etc ----
enum dir
{
	FORWARD, 
	RIGHT, 
	DOWN, 
	LEFT, 
};

// ---- The base class for which every entity in the game will be derived from ----

// IDEA : DERIVE THIS FROM INPUT HANDLE, MAYBE THIS WILL ALLOW US TO PLACE INPUTHANDLER HERE AND NOT IN PLAYER
class Entity
{
protected:
	// ---- Entity attributes ----
	sf::Vector2f pos; // entity position
	bool collider; // is this entity collidable?
	bool controllable; // can this entity be controlled by the player?
	float velocity;
	float hp;
	bool isControl; // a flag that says if this entity is currently moving

	Collision* col;

	// ---- Used for animation ----
	dir currentDir;

	// ---- What will be displayed of the entity ----
	sf::RectangleShape* entity; // This is the ACTUAL entity, the thing that will be displayed to the screen
	sf::Texture* entTexture; // the entities texture

	// ---- Animate row variables ----
	int forwardRow;
	int downRow;
	int leftRow;
	int rightRow;
	int maxAnim;
public:
	Entity();
	virtual ~Entity() = default;

	// ---- Entity info ----
	sf::Vector2f getPos();
	bool isPlayer(); // a flag that says if this entity is a player controlled entity
	
	virtual float getVelo();

	// ---- To be overrided ----
	//virtual void onInteract(Entity* ent); // this function will perform something when another entity interacts with this objects entity

	// ---- Return the entities figure (what needs to be rendered) --S--
	virtual sf::RectangleShape* getEnt();

	// ---- SFML Properties ----
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float deltaTime) = 0;

	// ---- Collision Properties ----
	void setCol(Collision& col_);

	// ---- Animation object to be used whenever he needs it ----
	Animation* animate; // this is public so each entity can have an animation feature and be accessed my commands
	virtual void setDir(dir dir_);

    virtual int getFRow();
	virtual int getDRow();
	virtual int getLRow();
	virtual int getRRow();
	virtual int getAnim();
};
#endif