#pragma once
#ifndef MY_UI
#define MY_UI

#include "Point.h"
#include<vector>

using std::vector;

class UI {
public:
	void makeUI();
	void printHelp();
	void makeBorder();
	static void gameOver();
};

#endif // !MY_UI
