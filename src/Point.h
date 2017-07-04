#pragma once
#ifndef MY_POINT
#define MY_POINT

#include<Windows.h>

class Point
{
public:
	Point();
	Point(const int x, const int y) : _x(x), _y(y) { };
	~Point() { };

	void setPoint(int x, int y);
	static void setOutPutPoint(const int x, const int y, HANDLE handle);
	void outPutCircular(HANDLE handle);
	void clear();
	void clear(HANDLE handle);
	bool operator== (const Point& point) const;
	int getX();
	int getY();

private:
	int _x, _y;
};


#endif