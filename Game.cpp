#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
////#include "Map.h"
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
	


	//std::vector <char> simb;
	//simb.resize(10);

	//simb[0] = '#';
	//simb[9] = '%';

	//simb.insert(simb.begin(), '@');
	//simb.insert(simb.begin() + 9, '&');


	//for (int j = 0; j < simb.size(); ++j)
	//{
	//	std::cout << simb[j];
	//}


	//print(simb, 10, 10);

	//Map map;
	//map.Print();
	
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


