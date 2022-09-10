#include "menu.h"
#include "Global.h"

using namespace std;

menu::menu(int id_menu) {
	menu_status = false;

}

void menu::title_menu(int id) {

	if (id == 1) {}
	else { cout << "\033[37m" << "\tPLAYING XXXX!\n\n\t1 - CONTINUE\n\n\t2 - HOW TO PLAY\n\n\t3 - INFO\n\n\t4 - ACHIEVEMENTS\n\n\t5 - QUIT"; }
}

void menu::menuopt(int x) {

	switch (x + 1)
	{
	case 2:
		system("cls");
		cout << "\n\n\tHOW TO PLAY ZORK\n\n";
		cout << "\n\n\tHere will be the text the help the players hay to play the game\n\n";
		system("pause");
		system("cls");
		break;

	case 3:
		system("cls");
		cout << "\n\n\tINFORMATION\n\n";
		cout << "\n\n\tThis game was developes by Alejandro Matus on 2022 for an online test for UPC School."
			"\n\n\tFor any questions, contact or comments please send an email to alejandromatusovejero@gmail.com"
			"\n\n\tCopyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>"
			"\n\tEveryone is permitted to copy and distribute verbatim copies"
			"\n\tof this license document, but changing it is not allowed.\n\n";
		system("pause");
		system("cls");
		break;

	case 4:
		system("cls");
		cout << "\n\n\tTHE ARCHIVE TOWER\n\n";
		cout << "\n\n\tHere will be the ACHIEVEMENTS fo the game"
			"\n\n\tTHE CHOOSEN ONE"
			"\n\n\t\tWIN THE GAME\n\n";
		system("pause");
		system("cls");
		break;

	default:
		system("cls");
		break;
	};
}
