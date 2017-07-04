#pragma once
#ifndef MY_SNAKE
#define MY_SNAKE

#include"Food.h"
#include<deque>

class Snake {
public:
	enum MoveDirection { UP, LEFT, DOWN, RIGHT };

private:
	std::deque<Point> _snake;
	MoveDirection _direction;

public:
	Snake();
	void createSnake(HANDLE handle);
	void changeDirection();
	bool isOppositeDir(MoveDirection dir);
	void move();	
	bool hitItself();									
	bool hitBorder();									
	bool isInSnakeBody(const Point& target);						
	bool isEat(Food& food);								
	Point& getSnakeHead();
	Point& getSnakeTail();
};

#endif // !MY_SNAKE
