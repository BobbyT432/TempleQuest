#ifndef COMMANDS
#define COMMANDS

#include "cmndmaster.h"

// ok i decided this might be an ok case to have multiple classes in one file that way we don't fill up tons of files with commands
class forwardCom : public Command
{
private:
	float velocity;
	sf::Vector2f tempPos;
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class downCom : public Command
{
private:
	float velocity;
	sf::Vector2f tempPos;
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class rightCom : public Command
{
private:
	float velocity;
	sf::Vector2f tempPos;
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class leftCom : public Command
{
private:
	float velocity;
	sf::Vector2f tempPos;
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class downRCom : public Command
{
private:
	float velocity;
	sf::Vector2f tempPos;
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class downLCom : public Command
{
private:
	float velocity;
	sf::Vector2f tempPos;
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class forwardRCom : public Command
{
private:
	float velocity;
	sf::Vector2f tempPos;
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class forwardLCom : public Command
{
private:
	float velocity;
	sf::Vector2f tempPos;
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class attackCom : public Command
{
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};

class deathCom : public Command
{
public:
	virtual void run(Entity& ent, float deltaTime, Collision& col);
};
#endif