#ifndef COMMANDS
#define COMMANDS

#include "cmndmaster.h"

// ok i decided this might be an ok case to have multiple classes in one file that way we don't fill up tons of files with commands
class forwardCom : public Command
{
private:
	float velocity;
public:
	virtual void run(Entity& ent, float deltaTime);
};

class downCom : public Command
{
private:
	float velocity;
public:
	virtual void run(Entity& ent, float deltaTime);
};

class rightCom : public Command
{
private:
	float velocity;
public:
	virtual void run(Entity& ent, float deltaTime);
};

class leftCom : public Command
{
private:
	float velocity;
public:
	virtual void run(Entity& ent, float deltaTime);
};

class downRCom : public Command
{
private:
	float velocity;
public:
	virtual void run(Entity& ent, float deltaTime);
};

class downLCom : public Command
{
private:
	float velocity;
public:
	virtual void run(Entity& ent, float deltaTime);
};

class forwardRCom : public Command
{
private:
	float velocity;
public:
	virtual void run(Entity& ent, float deltaTime);
};

class forwardLCom : public Command
{
private:
	float velocity;
public:
	virtual void run(Entity& ent, float deltaTime);
};
#endif