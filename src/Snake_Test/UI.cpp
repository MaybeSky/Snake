#include<iostream>
#include<conio.h>
#include"UI.h"
#include"Point.h"

using std::cout;


void UI::makeUI() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED);
	COORD position = { 17, 6 };
	SetConsoleCursorPosition(handle, position);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << " ¡ö¡ö¡ö   ¡ö     ¡ö  ¡ö¡ö¡ö  ¡ö    ¡ö ¡ö¡ö¡ö¡ö";
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	Point::setOutPutPoint(17, 7, handle);
	cout << "¡ö    ¡ö  ¡ö¡ö   ¡ö ¡ö    ¡ö ¡ö   ¡ö  ¡ö";
	Point::setOutPutPoint(17, 8, handle);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "¡ö        ¡ö ¡ö  ¡ö ¡ö    ¡ö ¡ö  ¡ö   ¡ö";
	Point::setOutPutPoint(17, 9, handle);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << " ¡ö¡ö¡ö   ¡ö  ¡ö ¡ö ¡ö¡ö¡ö¡ö ¡ö¡ö     ¡ö¡ö¡ö";
	Point::setOutPutPoint(17, 10, handle);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "      ¡ö  ¡ö   ¡ö¡ö ¡ö    ¡ö ¡ö  ¡ö   ¡ö";
	Point::setOutPutPoint(17, 11, handle);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "¡ö    ¡ö  ¡ö     ¡ö ¡ö    ¡ö ¡ö   ¡ö  ¡ö";
	Point::setOutPutPoint(17, 12, handle);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << " ¡ö¡ö¡ö   ¡ö     ¡ö ¡ö    ¡ö ¡ö    ¡ö ¡ö¡ö¡ö¡ö";
	cout << std::endl;

	printHelp();
	while (1) {
		Point::setOutPutPoint(27, 20, handle);
		cout << "Press any key to start...";
		Sleep(100);
		for (int i = 0; i < 25; i++)
			cout << "\b \b";
		Sleep(100);
		if (_kbhit())
			break;
	}
	std::cin.get();
	system("cls");
}

void UI::printHelp() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	Point::setOutPutPoint(22, 18, handle);
	cout << "W, S, A, D ¼ü¿ØÖÆ ÉÏ, ÏÂ, ×ó, ÓÒ " << std::endl;
}

void UI::makeBorder() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 12; i <= 70; i += 2) {
		for (int j = 0; j <= 22; j ++) {
			if ((i == 12) || (i == 70) || (j == 0) || (j == 22)) {
				Point::setOutPutPoint(i, j, handle);
				cout << "¡ö";
			}
		}
	}

	for (int i = 12; i <= 70; i += 2) {
		for (int j = 0; j <= 2; j++) {
			if ((i == 40) || (i == 42) || (j == 2)) {
				Point::setOutPutPoint(i, j, handle);
				cout << "¡ö";
			}
		}
	}
}

void UI::gameOver() {
	system("cls");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
	COORD position = { 13, 8 };
	SetConsoleCursorPosition(handle, position);
	cout << " ¡ö               ¡ö¡ö           ¡ö¡ö¡ö      ¡ö¡ö¡ö¡ö";
	Point::setOutPutPoint(13, 9, handle);
	cout << " ¡ö             ¡ö    ¡ö       ¡ö      ¡ö    ¡ö";
	Point::setOutPutPoint(13, 10, handle);
	cout << " ¡ö           ¡ö        ¡ö     ¡ö            ¡ö";
	Point::setOutPutPoint(13, 11, handle);
	cout << " ¡ö          ¡ö          ¡ö      ¡ö¡ö¡ö      ¡ö¡ö¡ö¡ö";
	Point::setOutPutPoint(13, 12, handle);
	cout << " ¡ö            ¡ö      ¡ö              ¡ö    ¡ö";
	Point::setOutPutPoint(13, 13, handle);
	cout << " ¡ö             ¡ö    ¡ö       ¡ö      ¡ö    ¡ö";
	Point::setOutPutPoint(13, 14, handle);
	cout << " ¡ö¡ö¡ö¡ö¡ö       ¡ö¡ö           ¡ö¡ö¡ö      ¡ö¡ö¡ö¡ö";
}