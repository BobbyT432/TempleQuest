#include "commands.h"

void forwardCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(0, -velocity);

	// ---- Animate the movement ----
	ent.animate->update(2, 6, deltaTime);
	ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(FORWARD);
}

void downCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	// ---- Move the entity ----
	ent.getEnt()->move(0, velocity);

	// ---- Animate the movement ----
	ent.animate->update(1, 6, deltaTime);
	//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(DOWN);
}

void rightCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(velocity, 0);

	// ---- Animate the movement ----
	ent.animate->update(4, 6, deltaTime);
	//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(RIGHT);
}

void leftCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(-velocity,0);

	// ---- Animate the movement ----
	ent.animate->update(3, 6, deltaTime);
	//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(LEFT);
}

void downRCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(velocity, velocity);

	// ---- Animate the movement ----
	ent.animate->update(1, 6, deltaTime);
	//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(DOWN);
}

void downLCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(-velocity, velocity);

	// ---- Animate the movement ----
	ent.animate->update(1, 6, deltaTime);
	//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(DOWN);
}

void forwardRCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(velocity, -velocity);

	// ---- Animate the movement ----
	ent.animate->update(2, 6, deltaTime);
	//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(FORWARD);
}

void forwardLCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(-velocity, -velocity);

	// ---- Animate the movement ----
	ent.animate->update(2, 6, deltaTime);
	//ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(FORWARD);
}
