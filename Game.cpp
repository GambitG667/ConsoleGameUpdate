#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Coordinates.h"
#include "Map.h"


void print(std::vector <char> simb, int x, int y)
{
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			std::cout << simb[i * y + j];
		}
		std::cout << std::endl;
	}

}


int main()
{	
	srand(time(NULL));

	Map map;
	map.Print();

	char mod;

	while (true)
	{
		

		mod = _getch();

		switch (mod)
		{
			case '8':
			{
				map.Up();
				break;
			}
			case '2':
			{
				map.Down();
				break;
			}
			case '4':
			{
				map.Left();
				break;
			}
			case '6':
			{
				map.Right();
				break;
			}
		}
		system("cls");
		map.Print();
	}
	return 0;
}


