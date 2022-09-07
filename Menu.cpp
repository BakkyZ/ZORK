#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include "Menu.h"
#include "Global.h"
#include "Game.h"

using namespace std;

int main()
{
	menu(0);
	return 0;

}

int menu(int p) {

	char pat;
	int x = p;

	cout << "\033[37m" << "\tWELLCOME TO XXXX!\n\n\t1 - PLAY\n\n\t2 - HOW TO PLAY\n\n\t3 - INFO\n\n\t4 - ACHIEVEMENTS\n\n\t5 - QUIT";
	
	if (x == 1) { cout << "\n\n\tCHOOSE A CORRECT PATH:   "; }
	else{ cout << "\n\n\tCHOOSE YOUR PATH:   "; }

	cout << "\t\033[35m";
	cin >> pat;
	switch (pat)
	{
	case '1':
		clean();
		game();
		break;

	case '2':
		clean();
		htp();
		break;

	case '3':
		clean();
		info();
		break;

	case '4':
		clean();
		achive();
		break;

	case '5':
		break;

	default:
		clean();
		menu(1);
	};

	return 0;
}

int htp() {

	clean(); cout << "\033[37m";
	cout << "\n\n\tHOW TO PLAY ZORK\n\n";
	cout << "\n\n\tHere will be the text the help the players hay to play the game\n\n";
	system("pause");
	clean();
	menu(0);
	return 0;
}

int info() {

	clean(); cout << "\033[37m";
	cout << "\n\n\tINFORMATION\n\n";
	cout << "\n\n\tThis game was developes by Alejandro Matus on 2022 for an online test for UPC School."
		    "\n\n\tFor any questions, contact or comments please send an email to alejandromatusovejero@gmail.com"
		    "\n\n\tCopyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>"
		    "\n\tEveryone is permitted to copy and distribute verbatim copies"
		    "\n\tof this license document, but changing it is not allowed.\n\n";
	system("pause");
	clean();
	menu(0);
	return 0;
}

int achive() {

	clean(); cout << "\033[37m";
	cout << "\n\n\tTHE ARCHIVE TOWER\n\n";
	cout << "\n\n\tHere will be the ACHIEVEMENTS fo the game"
		    "\n\n\tTHE CHOOSEN ONE"
			"\n\n\t\tWIN THE GAME\n\n";
	system("pause");
	clean();
	menu(0);
	return 0;
}

