#include "GameObject.h"

GameObject::GameObject()
{ 
	coordinates = Coordinates();
	state = new VoidState();
}

GameObject::GameObject(Coordinates coord)
{
	coordinates = coord;
	SetState(new VoidState());
}

GameObject::~GameObject()
{
	delete state;
}

void GameObject::SetState(StateGameObject* state)
{
	delete this->state;
	this->state = state;
}

void GameObject::SetCoordinates(Coordinates coord)
{
	coordinates = coord;
}

Coordinates GameObject::GetCoordinates()
{
	return coordinates;
}

int GameObject::GetInfo()
{
	return state->GetInfo(this);
}

bool GameObject::Transfer()
{
	return state->Transfer(this);
}

void GameObject::Hide()
{
	SetState(new HideState());
}

bool GameObject::ClearPlayer()
{
	SetState(new VoidState());
	return true;
}

bool StateGameObject::Transfer(GameObject* GO)
{
	return false;
}

bool StateGameObject::ClearPlayer(GameObject* GO)
{
	return false;
}

int HideState::GetInfo(GameObject* GO)
{
	return 0;
}

int VoidState::GetInfo(GameObject* GO)
{
	return 1;
}

bool VoidState::Transfer(GameObject* GO)
{
	GO->SetState(new PlayerState());
	return true;
}

int WallState::GetInfo(GameObject* GO)
{
	return 2;
}

int PlayerState::GetInfo(GameObject* GO)
{
	return 3;
}

bool PlayerState::ClearPlayer(GameObject* GO)
{
	GO->SetState(new VoidState());
	return true;
}

