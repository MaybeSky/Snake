#pragma once
#ifndef MY_SETGAME
#define MY_SETGAME

#include<string>
#include"Snake.h"
#include"UI.h"
class Game
{
public:
	Game();
	~Game();
	void createFood(Food& food);
	void initMode();
	void initScore();
	void updataMode();
	void updataScore();
	void changeSpeed();
	void playGame();
	void gameOver();
	bool isOverGame();

private:
	Snake _snake;
	Food _food;
	Point _border;
	UI _ui;
	int _score;
	int _speed;
	bool _isOverGame;
	std::string _mode;
};



#endif // !MY_SETGAME
