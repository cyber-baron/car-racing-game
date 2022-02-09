#include "car.h"


int main()
{
	int Set[] = { 7, 7, 7, 7, 7, 7, 7 };
	int counter = 2;
	char key;

	Point place;
	Enemy add;

	do
	{

		for (int i = 0;;)
		{
			setcursor(0, 0);
			srand((unsigned)time(NULL));
			system("cls");

			place.gotoxy(10, 5);
			color(Set[3]);
			std::cout << " -------------------------- ";

			place.gotoxy(10, 6);
			color(Set[4]);
			std::cout << " |        Car Game        | ";

			place.gotoxy(10, 7);
			color(Set[5]);
			std::cout << " --------------------------";

			place.gotoxy(10, 9);
			color(Set[0]);
			std::cout << "Start Game";

			place.gotoxy(10, 10);
			color(Set[1]);
			std::cout << "Instructions";

			place.gotoxy(10, 11);
			color(Set[6]);
			std::cout << "Change Game Theme";

			place.gotoxy(10, 12);
			color(Set[2]);
			std::cout << "Quit";

			key = _getche();

			if (key == 'w' && (counter >= 2 && counter <= 4))
				counter--;

			if (key == 's' && (counter >= 1 && counter <= 3))
				counter++;

			if (key == '\r')
			{
				if (counter == 1)
					add.play();

				else if (counter == 2)
					instructions();

				else if (counter == 3)
					changeTheme();

				else if (counter == 4)
					exit(0);
			}

			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			Set[6] = 7;

			if (counter == 1)
				Set[0] = 12;

			if (counter == 2)
				Set[1] = 12;

			if (counter == 3)
				Set[6] = 12;

			if (counter == 4)
				Set[2] = 12;

		}

	} while (1);

	return 0;
}