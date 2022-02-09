#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<conio.h>
#include<windows.h>

#include <SFML/Audio.hpp> //sfml for music (needed aditionl .dll files)

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70 

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

class Point //class to handel the movements
{

private:

	COORD CursorPosition;

public:

	void gotoxy(int x, int y)
	{
		CursorPosition.X = x;
		CursorPosition.Y = y;

		SetConsoleCursorPosition(console, CursorPosition);
	}

};

class Car 
{
private:

	char car[4][4] = { ' ','±','±',' ',
						'±','±','±','±',
						' ','±','±',' ',
						'±','±','±','±' };

public:

	void drawCar();
	void eraseCar();
};

class Enemy 
{
private:

	int enemyY[3];
	int enemyX[3];
	int enemyFlag[3];

public:

	void genEnemy(int ind);
	void drawEnemy(int ind);
	void eraseEnemy(int ind);
	void resetEnemy(int ind);

	int collision();
	void play();
};

class Theme //class to change the apearence of the game (have an opportunity to add more)
{

public:

	Theme(int colour)
	{
		switch (colour)
		{
		case 1:
		{
			SetConsoleTextAttribute(console, FOREGROUND_RED);
			break;
		}
		case 2:
		{
			SetConsoleTextAttribute(console, 14);
			break;
		}
		case 3:
		{
			SetConsoleTextAttribute(console, FOREGROUND_BLUE);
			break;
		}
		case 4:
		{
			SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			break;
		}
		default:
		{
			SetConsoleTextAttribute(console, 15);
			break;
		}
		}
	}

};

void instructions();

void changeTheme();
void chooseTheme();

void setcursor(bool visible, DWORD size);

void color(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }

#endif //!CAR_H
