#include "commands.h"

void forwardCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(0, -velocity);
}

void downCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	// ---- Move the entity ----
	ent.getEnt()->move(0, velocity);

	// ---- Animate the movement ----
	ent.animate->update(0, deltaTime);
	ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this

	// ---- Set the direction so the idle animation knows which way to face ----
	ent.setDir(DOWN);
}

void rightCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(velocity, 0);
}

void leftCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(-velocity,0);
}

void downRCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(velocity, velocity);

	// ---- Animate the movement ----
	ent.animate->update(0, deltaTime);
	ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this
}

void downLCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(-velocity, velocity);

	// ---- Animate the movement ----
	ent.animate->update(0, deltaTime);
	ent.getEnt()->setTextureRect(ent.animate->uvRect); // since uvRect is a public variable we can set it easily like this
}

void forwardRCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(velocity, -velocity);
}

void forwardLCom::run(Entity& ent, float deltaTime)
{
	velocity = ent.getVelo();

	ent.getEnt()->move(-velocity, -velocity);
}
