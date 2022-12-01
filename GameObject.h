#pragma once
#include "Coordinates.h"
#include <String>

class GameObject;
class StateGameObject;


class StateGameObject
{
private:
	Coordinates coordinates;
public:
	StateGameObject(){}
	virtual bool Transfer(GameObject* GO);
	virtual bool ClearPlayer(GameObject* GO);
	virtual int GetInfo(GameObject* GO) = 0;
};

class HideState : public StateGameObject
{
public:
	HideState() : StateGameObject(){}
	int GetInfo(GameObject* GO);
};

class VoidState : public StateGameObject
{
public:
	virtual int GetInfo(GameObject* GO);
	virtual bool Transfer(GameObject* GO);
	VoidState() : StateGameObject(){}
};

class WallState : public StateGameObject
{
public:
	virtual int GetInfo(GameObject* GO);
	WallState() : StateGameObject() {}
};

class PlayerState : public StateGameObject
{
public:
	virtual int GetInfo(GameObject* GO);
	virtual bool ClearPlayer(GameObject* GO);
	PlayerState() : StateGameObject() {}
};
 
class GameObject
{
private:
	Coordinates coordinates;
	StateGameObject* state=0;

public:

	GameObject();
	GameObject(Coordinates coord);
	~GameObject();
	void SetState(StateGameObject* state);
	void SetCoordinates(Coordinates coord);
	Coordinates GetCoordinates();
	bool Transfer();
	bool ClearPlayer();
	int GetInfo();
	void Hide();

};