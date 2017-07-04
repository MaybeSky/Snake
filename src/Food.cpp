#include<iostream>
#include<time.h>
#include "Food.h"
#include "Snake.h"


Food::Food() {
	_food.setPoint(20, 20);
}

Food::Food(const int x, const int y) {
	_food.setPoint(x, y);
}

void Food::setOutPutFood(const int x, const int y) {
	_food.setPoint(x, y);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Point::setOutPutPoint(x, y, handle);
	std::cout << "бя";
}

bool Food::isOutBorder(const int x, const int y) {
	if ((x < 14) || (x > 68) || (y < 3) || (y > 21))
		return true;
	return false;
}

Point& Food::getFood() {
	return _food;
}