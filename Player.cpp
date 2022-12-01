#include "Player.h"

Player::Player(Coordinates coord)
{
	coordinates = coord;
}

Coordinates Player::GetCoordinates()
{
	return coordinates;
}

void Player::Move(const std::string str)
{
	if (str == "UP")
	{
		coordinates.y += 1;
	}
	else if (str == "DOWN")
	{
		coordinates.y -= 1;
	}
	else if (str == "LEFT")
	{
		coordinates.x -= 1;
	}
	else if (str == "RIGHT")
	{
		coordinates.x += 1;
	}
}
