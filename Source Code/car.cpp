#include "car.h"

int carPos = WIN_WIDTH / 2;
int score = 0;
int num;

Point go;
Car car;
Enemy enemy;

void changeTheme()
{
	system("cls");

	std::cout << "Change Game Theme"
		"\n----------------"
		"\n We have different game themes, to choose one enter the following number: "
		"\n\n Press '1' to make a red theme"
		"\n Press '2' to make a yellow theme"
		"\n Press '3' to make a blue theme"
		"\n Press '4' to make a green theme"
		"\n Press '5' to make a white theme"
		"\n\n> ";

	std::cin >> num;

	chooseTheme();

	if (num == 1)
		std::cout << "\nNow Game Is Red/Black";
	else if (num == 2)
		std::cout << "\nNow Game Is Yellow/Black";
	else if (num == 3)
		std::cout << "\nNow Game Is Blue/Black";
	else if (num == 4)
		std::cout << "\nNow Game Is Green/Black";
	else if (num == 5)
		std::cout << "\nNow Game Is White/Black";

	_getch();
}

void chooseTheme()
{
	if (num == 1)
		Theme(1);
	else if (num == 2)
		Theme(2);
	else if (num == 3)
		Theme(3);
	else if (num == 4)
		Theme(4);
	else if (num == 5)
		Theme(5);
}

void setcursor(bool visible, DWORD size)
{
	if (size == 0)
		size = 20;

	CONSOLE_CURSOR_INFO lpCursor;

	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;

	SetConsoleCursorInfo(console, &lpCursor);
}

void drawBorder()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			go.gotoxy(0 + j, i);
			std::cout << "±";

			go.gotoxy(WIN_WIDTH - j, i);
			std::cout << "±";
		}
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		go.gotoxy(SCREEN_WIDTH, i);
		std::cout << "±";
	}
}

void Enemy::genEnemy(int ind)
{
	enemyX[ind] = 17 + rand() % (33);
}

void Enemy::drawEnemy(int ind)
{
	if (enemyFlag[ind] == true)
	{
		go.gotoxy(enemyX[ind], enemyY[ind]);
		std::cout << "****";

		go.gotoxy(enemyX[ind], enemyY[ind] + 1);
		std::cout << " ** ";

		go.gotoxy(enemyX[ind], enemyY[ind] + 2);
		std::cout << "****";

		go.gotoxy(enemyX[ind], enemyY[ind] + 3);
		std::cout << " ** ";
	}
}

void Enemy::eraseEnemy(int ind)
{
	if (enemyFlag[ind] == true)
	{
		go.gotoxy(enemyX[ind], enemyY[ind]);
		std::cout << "    ";

		go.gotoxy(enemyX[ind], enemyY[ind] + 1);
		std::cout << "    ";

		go.gotoxy(enemyX[ind], enemyY[ind] + 2);
		std::cout << "    ";

		go.gotoxy(enemyX[ind], enemyY[ind] + 3);
		std::cout << "    ";
	}
}

void Enemy::resetEnemy(int ind)
{
	eraseEnemy(ind);

	enemyY[ind] = 1;

	genEnemy(ind);
}


void Car::drawCar()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			go.gotoxy(j + carPos, i + 22);
			std::cout << car[i][j];
		}
	}
}

void Car::eraseCar()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			go.gotoxy(j + carPos, i + 22);
			std::cout << " ";
		}
	}
}

int Enemy::collision()
{
	if (enemyY[0] + 4 >= 23)
	{
		if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9)
			return 1;
	}

	return 0;
}

void updateScore()
{
	go.gotoxy(WIN_WIDTH + 7, 5);
	std::cout << "Score: " << score << "\n";
}

void instructions()
{

	system("cls");

	std::cout << "Instructions"
		"\n----------------"
		"\n Avoid Cars by moving left or right. "
		"\n\n Press 'a' to move left"
		"\n Press 'd' to move right"
		"\n Press 'escape' to exit"
		"\n\nPress any key to go back to menu";

	_getch();
}

void gameover()
{
	system("cls");

	std::cout << "\n"
		"\t\t--------------------------\n"
		"\t\t-------- Game Over -------\n"
		"\t\t--------------------------\n\n"
		"\t\tPress any key to go back to menu.";

	_getch();
}

void start()
{
	go.gotoxy(WIN_WIDTH + 7, 2);
	std::cout << "Car Game";

	go.gotoxy(WIN_WIDTH + 6, 4);
	std::cout << "----------";

	go.gotoxy(WIN_WIDTH + 6, 6);
	std::cout << "----------";

	go.gotoxy(WIN_WIDTH + 7, 12);
	std::cout << "Control ";

	go.gotoxy(WIN_WIDTH + 7, 13);
	std::cout << "-------- ";

	go.gotoxy(WIN_WIDTH + 2, 14);
	std::cout << " A Key - Left";

	go.gotoxy(WIN_WIDTH + 2, 15);
	std::cout << " D Key - Right";

	go.gotoxy(18, 5);
	std::cout << "Press any key to start";
}

void Enemy::play()
{
	chooseTheme();

	//music part (sfml needed)
	sf::Music music;
	music.openFromFile("sound.wav");
	music.play();
	music.setLoop(true);

	carPos = -1 + WIN_WIDTH / 2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemyY[0] = enemyY[1] = 1;

	system("cls");

	drawBorder();
	updateScore();

	genEnemy(0);
	genEnemy(1);

	start();

	_getch();

	go.gotoxy(18, 5);
	std::cout << "                      ";

	while (1)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'a' || ch == 'A')
			{
				if (carPos > 18)
					carPos -= 4;
			}

			if (ch == 'd' || ch == 'D')
			{
				if (carPos < 50)
					carPos += 4;
			}

			if (ch == 27)
				break;
		}

		car.drawCar();
		drawEnemy(0);
		drawEnemy(1);

		if (collision() == 1)
		{
			gameover();
			return;
		}

		Sleep(50);
		car.eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);

		if (enemyY[0] == 10)
			if (enemyFlag[1] == 0)
				enemyFlag[1] = 1;

		if (enemyFlag[0] == 1)
			enemyY[0] += 1;

		if (enemyFlag[1] == 1)
			enemyY[1] += 1;

		if (enemyY[0] > SCREEN_HEIGHT - 4)
		{
			resetEnemy(0);
			score++;
			updateScore();
		}

		if (enemyY[1] > SCREEN_HEIGHT - 4)
		{
			resetEnemy(1);
			score++;
			updateScore();
		}
	}
}