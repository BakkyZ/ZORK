#include "World.h"
#include "Global.h"

World::World()
{
	gamefinished = false;

	// WORLD CREATION
	//CREATING PATHS
	Room* path01 = new Room("Cell", "You are in a cell.");
	Room* path02 = new Room("Corridor", "A big corridor with a another cells.");
	Room* path03 = new Room("Yard", "Its really big and have a lot places to go.");
	Room* path04 = new Room("Restroom", "You see a few bes, looks like is where the guards sleep.");
	Room* path05 = new Room("Tower", "A vigilance tower, look empty.");
	Room* path06 = new Room("Gate", "Its a big gate and looks like the exit");
	Room* path07 = new Room("Roof", "Top of the Tower. Have a nice view.");
	Room* path08 = new Room("Outside", "You can feel the freedom.");

	// PATH 01 CELL
	Item* cell_key = new Item("lockpick", "\tMade for opening doors.\n", ItemType::KEY);
	Exit* exitp1top2 = new Exit("Corridor", ExitName(path02), Path::CORRIDOR, path01, path02, true, cell_key);
	path01->Insert(exitp1top2);
	path01->Insert(cell_key);
	entity.push_back(path01);


	// PATH 02 CORRIDOR
	Exit* exitp2top1 = new Exit("Cell", ExitName(path04), Path::CELL, path02, path01);
	Exit* exitp2top3 = new Exit("Yard", ExitName(path03), Path::YARD, path02, path03);
	path02->Insert(exitp2top1);
	path02->Insert(exitp2top3);
	entity.push_back(path02);

	// PAT 03 YARD
	Exit* exitp3top2 = new Exit("Corridor", ExitName(path02), Path::CORRIDOR, path03, path02);
	Exit* exitp3top4 = new Exit("Restroom", ExitName(path04), Path::RESTROOM, path03, path04);
	Exit* exitp3top5 = new Exit("Tower", ExitName(path05), Path::TOWER, path03, path05);
	Exit* exitp3top6 = new Exit("Gate", ExitName(path06), Path::GATE, path03, path06);
	Item* note = new Item("note", "\tI leave the key in the Restroom, im waiting in the Roof Tower\n");
	path03->Insert(exitp3top2);
	path03->Insert(exitp3top4);
	path03->Insert(exitp3top5);
	path03->Insert(exitp3top6);
	path03->Insert(note);
	entity.push_back(path03);


	// PATH 04 RESTROOM
	Exit* exitp4top3 = new Exit("Yard", ExitName(path03), Path::YARD, path04, path03);
	Item* gate_key = new Item("key", "\tMaster key of the bilding.\n", ItemType::KEY);
	path03->Insert(exitp4top3);
	path04->Insert(gate_key);
	entity.push_back(path04);

	// PATH 05 TOWER
	Exit* exitp5top3 = new Exit("Yard", ExitName(path03), Path::YARD, path05, path03);
	Exit* exitp5top7 = new Exit("Roof", ExitName(path07), Path::ROOF, path05, path07);
	Item* axe = new Item("axe", "\tIts a old axe.\n", ItemType::WEAPON);
	path05->Insert(axe);
	path05->Insert(exitp5top3);
	path05->Insert(exitp5top7);
	entity.push_back(path05);

	// PATH 06 GATE
	Exit* exitp6top3 = new Exit("Yard", ExitName(path03), Path::YARD, path06, path03);
	Exit* exitp6top8 = new Exit("Outside", ExitName(path08), Path::GATE, path06, path08, true, gate_key);
	path06->Insert(exitp6top3);
	path06->Insert(exitp6top8);
	entity.push_back(path06);

	// PATH 07 ROOF9
	Exit* exitp7top5 = new Exit("Tower", ExitName(path05), Path::TOWER, path07, path05);
	Enemy* guard = new Enemy("Guard", "\tA very fat guard.\n", path07);
	path07->Insert(guard);
	path07->Insert(exitp7top5);
	entity.push_back(path07);

	//ACHIVEMENTS


	//CREATE PLAYER AND SET POSITION
	player = new Player("Mistery", "You dont know who you are, keep going and find the exit", path01);
}

World::~World()
{
	for (Entity* e : entity)
	{
		delete e;
		e = nullptr;
	}
	entity.clear();
	delete player;
}

bool World::FinishGame() const
{
	return gamefinished;
}

bool World::MenuStatus() const
{
	return menu_status;
}
void World::SetMenu(bool status)
{
	menu_status = status;
}
void World::MenuOn()
{
	SetMenu(true);
	system("cls");
	cout << "\n\n\tPLAYING XXXX!\n\n\t1 - PLAY\n\n\t2 - HOW TO PLAY\n\n\t3 - INFO\n\n\t4 - ACHIEVEMENTS\n\n\t5 - QUIT\n\n";
}

void World::Play()
{
	system("cls");
	player->DescribePath();
	cout << "\n\n\t";
}

void World::Command_input(const vector<string>& words)
{


	switch (words.size()) {
	case 0:
		cout << "\tGive me a correct command!";
		break;
	case 1:
	case 2:
		Command_action(words);
		break;
	default:
		cout << "\tPlease type no more than 2 commands";
		break;
	}
}

void World::Command_menu(const vector<string>& words)
{
	string menu_op = Txt_to_low(words.at(0));
	if (words.size() > 1) {
		cout << "\tPlease type no more than 1 command";
	}
	else if (PLAY == menu_op || P_01 == menu_op)
	{
		SetMenu(false);
		Play();

	}
	else if (HOW == menu_op || INFO_02 == menu_op)
	{
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
		WaitingMenu();
	}
	else if (INFORMATION == menu_op || INFO_03 == menu_op)
	{
		system("cls");
		cout << "\n\n\tINFORMATION\n\n";
		cout << "\n\n\tThis game was developes by Alejandro Matus on 2022 for an online test for UPC School."
			"\n\n\tFor any questions, contact or comments please send an email to alejandromatusovejero@gmail.com"
			"\n\n\tCopyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>"
			"\n\tEveryone is permitted to copy and distribute verbatim copies"
			"\n\tof this license document, but changing it is not allowed.\n\n";
		WaitingMenu();
	}
	else if (ACHIEVEMENTS == menu_op || ACHI_04 == menu_op)
	{
		system("cls");
		cout << "\n\n\tTHE ARCHIVE TOWER\n\n";
		cout << "\n\n\tHere will be the ACHIEVEMENTS fo the game"
			"\n\n\tTHE CHOOSEN ONE"
			"\n\n\t\tWIN THE GAME\n\n";
		WaitingMenu();
	}
	else
	{
		cout << "\tIts not an menu option\n";
	}
}

void World::WaitingMenu()
{
	string wait;
	cout << "\n\n\tPress any key to go back to menu";
	//cin >> wait;
	system("cls");
	MenuOn();
}

void World::Command_action(const vector<string>& words)
{

	string cmd_01 = Txt_to_low(words.at(0));
	string cmd_02 = "";
	if (words.size() > 1) {
		cmd_02 = Txt_to_low(words.at(1));
	}

	if (MENU == cmd_01) {
		MenuOn();
	}
	else if (INVENTORY == cmd_01)
	{
		player->Inventory();
	}
	else if (LOOK == cmd_01)
	{
		player->Look(cmd_02);
	}
	else if (GO == cmd_01)
	{
		player->Go(cmd_02);
	}
	else if (TAKE == cmd_01)
	{
		player->Take(cmd_02);
	}
	else if (DROP == cmd_01)
	{
		player->Drop(cmd_02);
	}
	else if (EQUIP == cmd_01)
	{
		player->Equip(cmd_02);
	}
	else if (UNEQUIP == cmd_01)
	{
		player->Unequip(cmd_02);
	}
	else if (ATTACK == cmd_01)
	{
		player->Attack(cmd_02);
	}
	else if (OPEN == cmd_01)
	{
		player->Unlock(cmd_02);
	}
	else if (HELP == cmd_01)
	{
		cout << "\n\tUse menu command to see how to play";
	}
	else
	{
		cout << "\t" << cmd_01 << " its not an accion";
	}
}

string World::ExitName(Room* room) const
{
	return "\tExit to " + room->GetName() + ".";
}
