#pragma once
#include "Coordinates.h"
#include <string>

class Player
{
private:
	Coordinates coordinates;
public:
	Player(Coordinates coord);
	Coordinates GetCoordinates();
	void Move(const std::string str);
};

