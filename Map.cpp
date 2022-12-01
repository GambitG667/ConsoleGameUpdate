#include "Map.h"


Map::Map()
{
	

	MapArr.resize(HEIGHT);
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			MapArr[i].push_back(new GameObject(Coordinates(j,i)));
		}
	}

	Rooms.reserve(3);

	for (int i = 0; i < 3; ++i)
	{
		Coordinates min_coord(0, i * HEIGHT_ROOM);
		Coordinates max_coord(WIDTH_ROOM, (i + 1) * HEIGHT_ROOM);

		Rooms.push_back(new Room(FromToCoordinate(min_coord, max_coord), simbol_array, i,HEIGHT_ROOM,WIDTH_ROOM));
		Rooms[i]->SetCoordinates(min_coord, max_coord);

		if (0 < i && i < 2)
		{
			Rooms[i]->BuildDoor(WIDTH_ROOM / 2, 0);
			Rooms[i]->BuildDoor(WIDTH_ROOM / 2, HEIGHT_ROOM-1);
		}
		else if (i == 0)
		{
			
			Rooms[i]->BuildDoor(WIDTH / 2, HEIGHT_ROOM - 1);
		}
		else if (i == 2)
		{
			Rooms[i]->BuildDoor(WIDTH_ROOM / 2, 0);
		}

	}

	player = new Player(Coordinates(WIDTH_ROOM / 2, HEIGHT_ROOM / 2));

	OnCoordinate(player->GetCoordinates())->SetState(new PlayerState());

	ActivRoom = Rooms[0];

}

Map::~Map()
{
	for (std::vector <GameObject*> i : MapArr)
	{
		for (GameObject* j : i)
		{
			delete j;
		}
	}
	for (Room* i : Rooms)
	{
		delete i;
	}
	delete player;
}

std::vector <std::vector <GameObject*>> Map::FromToCoordinate(Coordinates begin_coord, Coordinates end_coord)
{
	std::vector <std::vector <GameObject*>> RoomArr;

	RoomArr.resize(end_coord.y - begin_coord.y);

	for (int h = begin_coord.y, i = 0; h < end_coord.y; ++h,++i)
	{
		for (int w = begin_coord.x; w < end_coord.x; ++w)
		{
			RoomArr[i].push_back(OnCoordinate(Coordinates(w, h)));
		}
	}

	return RoomArr;
}

GameObject* Map::OnCoordinate(Coordinates coord)
{
	return MapArr[coord.y][coord.x];
}

void Map::Print()
{
	ActivRoom->PrintRoom();
}	

void Map::LoocActivRoom()
{
	if (!ActivRoom->IsInRoom(player->GetCoordinates()))
	{
		for (Room* r : Rooms)
		{
			r->IsInRoom(player->GetCoordinates()) ? ActivRoom = r : 0;
		}
	}

}

void Map::Up()
{

	if (OnCoordinate(player->GetCoordinates().plus(0, 1))->Transfer())
	{
		OnCoordinate(player->GetCoordinates())->ClearPlayer();
		player->Move("UP");
	}
	LoocActivRoom();
}

void Map::Down()
{
	if (OnCoordinate(player->GetCoordinates().minus(0, 1))->Transfer())
	{
		OnCoordinate(player->GetCoordinates())->ClearPlayer();
		player->Move("DOWN");
	}
	LoocActivRoom();
}

void Map::Right()
{
	if (OnCoordinate(player->GetCoordinates().plus(1, 0))->Transfer())
	{
		OnCoordinate(player->GetCoordinates())->ClearPlayer();
		player->Move("RIGHT");
	}
	LoocActivRoom();
}

void Map::Left()
{
	if (OnCoordinate(player->GetCoordinates().minus(1, 0))->Transfer())
	{
		OnCoordinate(player->GetCoordinates())->ClearPlayer();
		player->Move("LEFT");
	}
	LoocActivRoom();
}



