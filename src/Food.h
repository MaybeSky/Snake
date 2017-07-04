#pragma once
#ifndef MY_FOOD
#define MY_FOOD

#include"Point.h"

class Food
{
public:
	Food();
	Food(const int x, const int y);
	~Food() { };

	void setOutPutFood(const int x, const int y);
	bool isOutBorder(const int x, const int y);
	Point& getFood();

private:
	Point _food;
};



#endif // !MY_FOOD
