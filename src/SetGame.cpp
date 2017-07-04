#include<iostream>
#include<conio.h>
#include<time.h>
#include"SetGame.h"
#include"UI.h"

using std::cout;
using std::endl;

Game::Game() {
	_speed = 300;
	_score = 0;
	_mode = "简单";
	_isOverGame = false;
	_ui.makeBorder();
}

Game::~Game() {

}

void Game::createFood(Food& food) {
	srand(static_cast<unsigned> (time(NULL)));
	int foodX, foodY;
	while (1) {
		foodX = rand() % (54 / 2) * 2 + 14;
		foodY = rand() % (18 / 2) * 2 + 3;
		if (food.isOutBorder(foodX, foodY) || _snake.isInSnakeBody(Point(foodX, foodY)))
			continue;
		else
			break;
	}
	food.setOutPutFood(foodX, foodY);
	
}

void Game::initMode() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Point::setOutPutPoint(20, 1, handle);
	cout << "模式: " << _mode;
}

void Game::initScore() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Point::setOutPutPoint(52, 1, handle);
	cout << "分数: " << _score;
}

void Game::updataMode() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Point::setOutPutPoint(26, 1, handle);
	if (_score <= 500) 
		_mode = "简单";
	else if (_score > 500 && _score <= 1000) 
		_mode =  "普通";
	else if (_score > 1000 && _score <= 2000) 
		_mode = "困难";
	else if (_score >2000 && _score <= 2500)
		_mode = "地狱";
	else if (_score >= 3000)
		_mode = "疯狂";
	cout << _mode;
}

void Game::updataScore() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Point::setOutPutPoint(58, 1, handle);
	_score += 100;
	cout << _score;
}

void Game::changeSpeed() {
	if (_score <= 500)
		_speed = 250;
	else if (_score > 500 && _score <= 1000)
		_speed = 200;
	else if (_score >1000 && _score<= 2000)
		_speed = 150;
	else if (_score >2000 && _score <= 2500)
		_speed = 100;
	else if (_score >= 3000)
		_speed = 50;
}

void Game::playGame() {
	initMode();
	initScore();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	_food.setOutPutFood(20, 11);
	_snake.createSnake(handle);

	while (1) {
		_snake.getSnakeTail().clear(handle);
		_snake.changeDirection();
		changeSpeed();
		bool eaten = _snake.isEat(_food);
		if (eaten) {
			createFood(_food);
			updataScore();
			updataMode();
		}
		else
			_snake.move();
		_snake.getSnakeHead().outPutCircular(handle);

		if (_snake.hitBorder() || _snake.hitItself())
			break;
		Sleep(_speed);
	}
}

void Game::gameOver() {
	system("cls");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE);
	Point::setOutPutPoint(6, 6, handle);
	cout << "**************************  Game Over  *****************************";
	Point::setOutPutPoint(6, 10, handle);
	cout << "**************************  Score: " << _score << " *******************************";
	Point::setOutPutPoint(6, 14, handle);
	cout << "**************************  Play Again? (Y/N) **********************";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 'n' || ch == 'N') {
			_isOverGame = true;
			UI::gameOver();
		}
		else if (ch == 'y' || ch == 'Y')
			break;
	}
	system("cls");
}

bool Game::isOverGame() {
	return _isOverGame;
}