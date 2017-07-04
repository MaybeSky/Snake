#include"Snake.h"
#include<conio.h>

Snake::Snake() {
	_snake.push_front(Point(22, 11));
	_snake.push_front(Point(24, 11));
	_snake.push_front(Point(26, 11));
	_direction = MoveDirection::RIGHT;
}

void Snake::createSnake(HANDLE handle) {
	for (Point& point : _snake) {
		Point::setOutPutPoint(point.getX(), point.getY(), handle);
		point.outPutCircular(handle);
	}
}

void Snake::changeDirection() {
	char key;
	if (_kbhit()) {
		key = _getch();
		switch (key)
		{
		case 'w': case 'W':
			isOppositeDir(MoveDirection::UP);
			break;
		case 's' : case 'S':
			isOppositeDir(MoveDirection::DOWN);
			break;
		case 'a' : case 'A':
			isOppositeDir(MoveDirection::LEFT);
			break;
		case 'd' : case 'D':
			isOppositeDir(MoveDirection::RIGHT);
			break;
		default:
			break;
		}
	}
}

void Snake::move() {
	switch (_direction)
	{
	case MoveDirection::UP:
		_snake.push_front(Point(_snake.begin()->getX(), _snake.begin()->getY() - 1)); break;
	case MoveDirection::LEFT:
		_snake.push_front(Point(_snake.begin()->getX() - 2, _snake.begin()->getY())); break;
	case MoveDirection::RIGHT:
		_snake.push_front(Point(_snake.begin()->getX() + 2, _snake.begin()->getY())); break;
	case MoveDirection::DOWN:
		_snake.push_front(Point(_snake.begin()->getX(), _snake.begin()->getY() + 1)); break;
	default:
		break;
	}
	_snake.pop_back();
}

bool Snake::isOppositeDir(Snake::MoveDirection dir){
	if ((dir + 2) % 4 == _direction)
		return false;
	else {
		_direction = dir;
		return true;
	}
}

bool Snake::hitItself() {
	for (const Point& point : _snake) {
		if (*_snake.begin() == point) {
			if (&(*_snake.begin()) == &point)
				continue;
			else
				return true;
		}
	}
	return false;
}

bool Snake::hitBorder() {
	int x = _snake.begin()->getX();
	int y = _snake.begin()->getY();
	if (x == 12 || x == 70 || y == 2 || y == 22)
		return true;
	return false;
}

bool Snake::isInSnakeBody(const Point& target) {
	for (const Point& body : _snake)
		if (body == target)
			return true;
	return false;
}

bool Snake::isEat(Food& food) {
	int foodX = food.getFood().getX();
	int foodY = food.getFood().getY();
	int headX = _snake.begin()->getX();
	int headY = _snake.begin()->getY();

	bool toEat = ((headX == foodX - 2) && (headY == foodY) && (_direction == MoveDirection::RIGHT)
		|| (headX == foodX + 2) && (headY == foodY) && (_direction == MoveDirection::LEFT)
		|| (headX == foodX) && (headY == foodY + 1) && (_direction == MoveDirection::UP)
		|| (headX == foodX) && (headY == foodY - 1) && (_direction == MoveDirection::DOWN));

	if (toEat) {
		_snake.push_front(food.getFood());
		return true;
	}
	return false;
}

Point& Snake::getSnakeHead() {
	return *_snake.begin();
}

Point& Snake::getSnakeTail(){
	return *(_snake.end() - 1);
}


