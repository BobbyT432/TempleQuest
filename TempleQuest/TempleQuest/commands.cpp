#include "commands.h"

void forwardCom::run(Entity& ent, float deltaTime, Collision &col)
{
	velocity = ent.getVelo();
	
	tempPos = ent.getPos(); // holds current position of the entity
	
	tempPos.y -= velocity; // added velocity to show what the FUTURE position would be

	if (col.getGridCol(col.getGridLoc(tempPos)) == 0) // checks the future positions grid location to see if its a collider or not
	{
		// ---- Move the entity ----
		ent.getEnt()->move(0, -velocity);
	}
		// ---- Animate the movement ----
	ent.animate->update(ent.getFRow(), ent.getAnim() , deltaTime); // row, row count
	
	ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

		// ---- Set the direction so the idle animation knows which way to face ----
		ent.setDir(FORWARD);
	
}

void downCom::run(Entity& ent, float deltaTime, Collision& col)
{
	velocity = ent.getVelo();

	tempPos = ent.getPos(); // holds current position of the entity

	tempPos.y += velocity; // added velocity to show what the FUTURE position would be

	if (col.getGridCol(col.getGridLoc(tempPos)) == 0) // checks the future positions grid location to see if its a collider or not
	{
		// ---- Move the entity ----
		ent.getEnt()->move(0, velocity);
	}
		// ---- Animate the movement ----
		ent.animate->update(ent.getDRow(), ent.getAnim(), deltaTime);
		//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

		// ---- Set the direction so the idle animation knows which way to face ----
		ent.setDir(DOWN);
	
}

void rightCom::run(Entity& ent, float deltaTime, Collision& col)
{
	velocity = ent.getVelo();

	tempPos = ent.getPos(); // holds current position of the entity

	tempPos.x += velocity; // added velocity to show what the FUTURE position would be

	if (col.getGridCol(col.getGridLoc(tempPos)) == 0) // checks the future positions grid location to see if its a collider or not
	{
		// ---- Move the entity ----
		ent.getEnt()->move(velocity, 0);
	}
		// ---- Animate the movement ----
		ent.animate->update(ent.getRRow(), ent.getAnim(), deltaTime);
		//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

		// ---- Set the direction so the idle animation knows which way to face ----
		ent.setDir(RIGHT);
	
}

void leftCom::run(Entity& ent, float deltaTime, Collision& col)
{
	velocity = ent.getVelo();

	tempPos = ent.getPos(); // holds current position of the entity

	tempPos.x -= velocity; // added velocity to show what the FUTURE position would be

	if (col.getGridCol(col.getGridLoc(tempPos)) == 0) // checks the future positions grid location to see if its a collider or not
	{
		// ---- Move the entity ----
		ent.getEnt()->move(-velocity, 0);
	}
		// ---- Animate the movement ----
		ent.animate->update(ent.getLRow(), ent.getAnim(), deltaTime);
		//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

		// ---- Set the direction so the idle animation knows which way to face ----
		ent.setDir(LEFT);
	
}

void downRCom::run(Entity& ent, float deltaTime, Collision& col)
{
	velocity = ent.getVelo();

	tempPos = ent.getPos(); // holds current position of the entity

	tempPos.x += velocity;
	tempPos.y += velocity; // added velocity to show what the FUTURE position would be

	if (col.getGridCol(col.getGridLoc(tempPos)) == 0) // checks the future positions grid location to see if its a collider or not
	{
		// ---- Move the entity ----
		ent.getEnt()->move(velocity, velocity);
	}
		// ---- Animate the movement ----
		ent.animate->update(ent.getDRow(), ent.getAnim(), deltaTime);
		//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

		// ---- Set the direction so the idle animation knows which way to face ----
		ent.setDir(DOWN);
	
}

void downLCom::run(Entity& ent, float deltaTime, Collision& col)
{
	velocity = ent.getVelo();

	velocity = ent.getVelo();

	tempPos = ent.getPos(); // holds current position of the entity

	tempPos.x -= velocity;
	tempPos.y += velocity; // added velocity to show what the FUTURE position would be

	if (col.getGridCol(col.getGridLoc(tempPos)) == 0) // checks the future positions grid location to see if its a collider or not
	{
		// ---- Move the entity ----
		ent.getEnt()->move(-velocity, velocity);
	}
		// ---- Animate the movement ----
		ent.animate->update(ent.getDRow(), ent.getAnim(), deltaTime);
		//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

		// ---- Set the direction so the idle animation knows which way to face ----
		ent.setDir(DOWN);
	
}

void forwardRCom::run(Entity& ent, float deltaTime, Collision& col)
{
	velocity = ent.getVelo();

	velocity = ent.getVelo();

	tempPos = ent.getPos(); // holds current position of the entity

	tempPos.x += velocity;
	tempPos.y -= velocity; // added velocity to show what the FUTURE position would be

	if (col.getGridCol(col.getGridLoc(tempPos)) == 0) // checks the future positions grid location to see if its a collider or not
	{
		// ---- Move the entity ----
		ent.getEnt()->move(velocity, -velocity);
	}
		// ---- Animate the movement ----
		ent.animate->update(ent.getFRow(), ent.getAnim(), deltaTime);
		//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

		// ---- Set the direction so the idle animation knows which way to face ----
		ent.setDir(FORWARD);
	
}

void forwardLCom::run(Entity& ent, float deltaTime, Collision& col)
{
	velocity = ent.getVelo();

	velocity = ent.getVelo();

	tempPos = ent.getPos(); // holds current position of the entity

	tempPos.x -= velocity;
	tempPos.y -= velocity; // added velocity to show what the FUTURE position would be

	if (col.getGridCol(col.getGridLoc(tempPos)) == 0) // checks the future positions grid location to see if its a collider or not
	{
		// ---- Move the entity ----
		ent.getEnt()->move(-velocity, -velocity);
	}
		// ---- Animate the movement ----
		ent.animate->update(ent.getFRow(), ent.getAnim(), deltaTime);
		//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

		// ---- Set the direction so the idle animation knows which way to face ----
		ent.setDir(FORWARD);
	
}
