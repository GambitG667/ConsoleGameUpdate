#pragma once
#ifndef	SCREAN_H_
#define SCREEN_H_
#include <iostream>
#include <vector>
#include "GameObject.h"

struct ScreenArray
{
	std::vector <std::vector <GameObject*>> screenArray;
	int width;
	int height;
	ScreenArray(std::vector <std::vector <GameObject*>> sA,int w,int h)
	{
		screenArray = sA;
		width = w;
		height = h;
	}
};

class Screen
{
private:

	std::vector <std::vector <GameObject*>> screenArray;

	char *simbolsArray;

	int width;
	int height;

public:

	Screen()
	{
		screenArray;

		simbolsArray = 0;

		height = 0;
		width = 0;
	}

	Screen(ScreenArray screenArr, char* simbolsArr)
	{
		screenArray = screenArr.screenArray;

		simbolsArray = simbolsArr;

		height = screenArr.height;
		width = screenArr.width;
	}

	void print()
	{
		for (int i = height-1 ; i >= 0; --i)
		{
			for (int j = 0; j < width; ++j)
			{
				std::cout << simbolsArray[screenArray[i][j]->GetInfo()];
				/*std::cout << screenArray[i][j]->GetCoordinates().x << "," << screenArray[i][j]->GetCoordinates().y << " ";*/
			}
			std::cout << std::endl;
		}
	}
};

#endif