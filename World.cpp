#include "World.h"
#include "menu.h"

menu Mymenu(2);

World::World() {

	gamefinished = false;

}

World::~World() {}

bool World::FinishGame() const {
	return gamefinished;
}

void World::Play() {
	cout << "\tGAME START";
}

void World::Command_input(const vector<string>& words) {


	switch (words.size()) {
	case 0:
		cout << "\tGive me a correct command!";
		break;
	case 1:
	case 2:
		Command_action(words);
		break;
	default:
		cout << "\tPlease type no more than 2 words";
		break;
	}
}

void World::Command_menu(int menu_op)
{
	if (1 == menu_op) {Mymenu.menuopt(1);} //play
	else if (2 == menu_op) {Mymenu.menuopt(2);} // how play
	else if (3 == menu_op) {Mymenu.menuopt(3);} // info
	else if (4 == menu_op) {Mymenu.menuopt(4);} // archivement
}

void World::Command_action(const vector<string>& words) {

	string cmd_01 = Txt_to_low(words.at(0));
	string cmd_02 = "";
	if (words.size() > 1) {
		cmd_02 = Txt_to_low(words.at(1));
	}

	if (MENU == cmd_01) {
		cout << "\n\n\t2 - HOW PLAY\n\n\t3 - INFO\n\n\t4 - ACHIEVEMENTS\n\n\t5 - QUIT";
	}
	else if (INVENTORY == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (LOOK == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (GO == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (TAKE == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (DROP == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (EQUIP == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (UNEQUIP == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (ATTACK == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (OPEN == cmd_01) {
		cout << "\tYOU " << cmd_01;
	}
	else if (HELP == cmd_01) {
		Help();
	}
	else
		cout << "\tIts not an accion";
}


void World::Help() const {

	cout << "\n\tAction Commands:"
		"\n\tInventory - shows the items you have."
		"\n\tLook      - describe the object you specify."
		"\n\tGo        - move the player to a different room."
		"\n\tTake      - take an item."
		"\n\tDrop      - drop the item from your inventory."
		"\n\tEquipe    - take an item to can use it."
		"\n\tUnequip   - put the equipe item in the inventory."
		"\n\tAttack    - attack a monster in the current room."
		"\n\tOpen      - opens an object you specify. Only if is possible."
		"\n\tExit/quit - close the game. You will lose the progress";
}