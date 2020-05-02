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
	float targetAggro;// aggro range for AI
	float atkRange; // range of attack
	float knockback; // amount of pixels to send target backwards
	float hpDealt; // how much hp to subtract when attacking
	sf::Vector2f targetPos; // For AI

	Collision* col;

	// ---- Used for animation ----
	dir currentDir;

	// ---- What will be displayed of the entity ----
	sf::RectangleShape* entity; // This is the ACTUAL entity, the thing that will be displayed to the screen
	sf::Texture* entTexture; // the entities texture

	// ---- Animate row variables ----
	float forwardRow;
	float downRow;
	float leftRow;
	float rightRow;
	float attackFRow;
	float attackDRow;
	float attackLRow;
	float attackRRow;
	float DDRow;
	float DDColumn;
	float maxAnim;

	// ---- Contains all entities on a level, allows for collision checking on entities with eachother ----
	std::list<Entity*> entGroup;
public:
	Entity();
	virtual ~Entity() = default;

	// ---- Entity info ----
	sf::Vector2f getPos();
	bool isPlayer(); // a flag that says if this entity is a player controlled entity
	
	virtual float getVelo();

	// ---- To be overrided ----
	virtual void onInteract() = 0;
	virtual void setGroup(std::list<Entity*> &entGroup_);
	virtual std::list<Entity*>* getGroup();

	// ---- Return the entities figure (what needs to be rendered) --S--
	virtual sf::RectangleShape* getEnt();

	// ---- SFML Properties ----
	virtual void draw(sf::RenderWindow& window);
	virtual bool update(float deltaTime) = 0;

	// ---- Collision Properties ----
	void setCol(Collision& col_);

	// ---- Animation object to be used whenever he needs it ----
	Animation* animate; // this is public so each entity can have an animation feature and be accessed my commands
	virtual void setDir(dir dir_);
	virtual dir getDir();

	// ---- Animation properties ----
    virtual float getFRow();
	virtual float getDRow();
	virtual float getLRow();
	virtual float getRRow();
	virtual float getAFRow();
	virtual float getADRow();
	virtual float getALRow();
	virtual float getARRow();
	virtual float getDDRow();
	virtual float getDDCol();
	virtual float getAnim();

	// ---- Character attributes ----
	virtual void minusHP(float hp_);
	virtual void addHP(float hp_);
	virtual float getHP();

	// ---- For AI ----
	virtual void setTarget(sf::Vector2f targetPos_);
};
#endif