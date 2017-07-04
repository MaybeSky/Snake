#include<iostream>
#include"Point.h"

Point::Point() {
	_x = _y = 1;
}

void Point::setPoint(int x, int y) {
	_x = x;
	_y = y;
}

void Point::setOutPutPoint(const int x, const int y, HANDLE handle) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void Point::outPutCircular(HANDLE handle) {
	setOutPutPoint(_x, _y, handle);
	std::cout << "¡ñ";
}

void Point::clear() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << " ";
}

void Point::clear(HANDLE handle) {
	setOutPutPoint(_x, _y, handle);
	std::cout << " ";
}

bool Point::operator==(const Point& point) const {
	if ((_x == point._x) && (_y == point._y))
		return true;
	return false;
}

int Point::getX() {
	return _x;
}

int Point::getY() {
	return _y;
}