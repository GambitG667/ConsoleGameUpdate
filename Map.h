#pragma once
#include <vector>
#include "GameObject.h"
#include "Room.h"
#include "Player.h"



class Map
{
private:

	int HEIGHT = 60;
	int WIDTH = 60;

	int HEIGHT_ROOM = 20;
	int WIDTH_ROOM = 60;

	char simbol_array[5]{ 32, 44, 35, 64 };

	Room* ActivRoom;
	Player* player;

	std::vector <std::vector <GameObject*>> MapArr;
	std::vector <Room*> Rooms;

public:

	Map();
	~Map();
	std::vector <std::vector <GameObject*>> FromToCoordinate(Coordinates begin_coord, Coordinates end_coord);
	GameObject* OnCoordinate(Coordinates coord);
	void Print();
	void LoocActivRoom();
	void Up();
	void Down();
	void Right();
	void Left();

};