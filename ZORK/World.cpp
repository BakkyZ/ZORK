#include "World.h"
#include "Global.h"
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __unix__
#include <unistd.h>
#endif

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
	Room* path07 = new Room("Armery", "Place for store weapons");
	Room* path08 = new Room("Outside", "You can feel the freedom.");

	// PATH 01 CELL
	Item* cell_key = new Item("lockpick", "\tMade for opening doors.\n", ItemType::KEY);
	Exit* exitp1top2 = new Exit("Corridor", ExitName(path02), Path::CORRIDOR, path01, path02, true, cell_key);
	Achievement* captured = new Achievement("Captured", "You was captured and leave in a cell.");
	path01->Insert(cell_key);
	path01->Insert(exitp1top2);
	path01->Insert(captured);
	entity.push_back(path01);

	// PATH 02 CORRIDOR
	Item* rest_key = new Item("key", "\tMade for opening storeroom path.\n", ItemType::KEY);
	Achievement* thecorridor = new Achievement("Not a Prisoner", "You succesfully get out from the Cell.");
	Exit* exitp2top1 = new Exit("Cell", ExitName(path01), Path::CELL, path02, path01);
	Exit* exitp2top3 = new Exit("Yard", ExitName(path03), Path::YARD, path02, path03);
	Exit* exitp2top7 = new Exit("Armery", ExitName(path07), Path::ARMERY, path02, path07, true, rest_key);
	path02->Insert(thecorridor);
	path05->Insert(rest_key);
	path02->Insert(exitp2top1);
	path02->Insert(exitp2top3);
	path02->Insert(exitp2top7);
	entity.push_back(path02);

	// PAT 03 YARD
	Achievement* theyard = new Achievement("The Yard", "You visit the yard.");
	Item* note = new Item("note", "\tI clean my gun and store in the Armery and leave my uniform in the Restroom.\n");
	Exit* exitp3top2 = new Exit("Corridor", ExitName(path02), Path::CORRIDOR, path03, path02);
	Exit* exitp3top4 = new Exit("Restroom", ExitName(path04), Path::RESTROOM, path03, path04);
	Exit* exitp3top5 = new Exit("Tower", ExitName(path05), Path::TOWER, path03, path05);
	Exit* exitp3top6 = new Exit("Gate", ExitName(path06), Path::GATE, path03, path06);
	path03->Insert(note);
	path03->Insert(theyard);
	path03->Insert(exitp3top2);
	path03->Insert(exitp3top4);
	path03->Insert(exitp3top5);
	path03->Insert(exitp3top6);
	entity.push_back(path03);

	// PATH 04 RESTROOM
	Item* uniform = new Item("Uniform", "\tIts a guard uniform.\n", ItemType::KEY);
	Achievement* officer = new Achievement("Like a Oficcer", "You enter in the Oficcers Restroom.");
	Exit* exitp4top3 = new Exit("Yard", ExitName(path03), Path::YARD, path04, path03);
	path04->Insert(uniform);
	path04->Insert(officer);
	path04->Insert(exitp4top3);
	entity.push_back(path04);

	// PATH 05 TOWER
	Exit* exitp5top3 = new Exit("Yard", ExitName(path03), Path::YARD, path05, path03);
	path05->Insert(exitp5top3);
	entity.push_back(path05);

	// PATH 06 GATE
	Enemy* guard = new Enemy("Guard", "\tA very fat guard.\n", path06);
	Exit* exitp6top3 = new Exit("Yard", ExitName(path03), Path::YARD, path06, path03);
	Exit* exitp6top8 = new Exit("Outside", ExitName(path08), Path::OUTSIDE, path06, path08, true, uniform);
	path06->Insert(guard);
	path06->Insert(exitp6top3);
	path06->Insert(exitp6top8);
	entity.push_back(path06);

	// PATH 07 ARMERY
	Item* pistol = new Item("Pistol", "\tIts a 9mm pistol.\n", ItemType::WEAPON);
	Item* bullets = new Item("Magazine", "\tSome bullets for the 9mm.\n", ItemType::BULLET);
	Achievement* thearmery = new Achievement("Gunslinger", "You succesfully enter into the armery.");
	Exit* exitp7top2 = new Exit("Corridor", ExitName(path02), Path::CORRIDOR, path07, path02);
	path07->Insert(pistol);
	path07->Insert(bullets);
	path07->Insert(thearmery);
	path07->Insert(exitp7top2);
	entity.push_back(path07);

	// PATH 08 OUTSIDE

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
void World::SetFinishGame(bool status)
{
	gamefinished = status;
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
	system("cls");
	SetMenu(true);
	cout << "\n\n\tPLAYING ZORK!\n\n\t1 - PLAY\n\n\t2 - HOW TO PLAY\n\n\t3 - INFO\n\n\t4 - ACHIEVEMENTS\n\n\t5 - QUIT\n\n";
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
		Play();
		cout << "\tGive me a correct command!";
		break;
	case 1:
	case 2:
	case 3:
		Command_action(words);
		break;
	default:
		Play();
		cout << "\tPlease type no more than 2 commands";
		break;
	}
}

void World::Command_menu(const vector<string>& words)
{
	string menu_op = Txt_to_low(words.at(0));
	
	if (words.size() > 1)
	{
		MenuOn();
		cout << "\tPlease type no more than 1 command";
	}
	else if (PLAY == menu_op || P_01 == menu_op)
	{
		player->GetAchievement();
		SetMenu(false);
		Play();
	}
	else if (HOW == menu_op || INFO_02 == menu_op)
	{
		system("cls");
		cout << "\n\n\tAction Commands:\n"
			"\n\tInventory - shows the items you have."
			"\n\tLook      - describe the object you specify."
			"\n\tGo        - move the player to a different path."
			"\n\tTake      - take an item."
			"\n\tDrop      - drop a item what you have, equiped or stored."
			"\n\tEquip     - take an inventary item to can use it."
			"\n\tUnequip   - put the equipe item in the inventory."
			"\n\tInsert    - to inster one item inside other item."
			"\n\tAttack    - attack a monster in the current path."
			"\n\tOpen      - opens an object you specify. Only if is possible."
			"\n\tExit/quit - close the game. You will lose the progress"
			"\n\n\tHere are some examples"
			"\n\tCommnad go/open you must choose a path ej: go cell "
			"\n\tCommnad take/equipe/drop/unequipe you must choose a item ej: take key "
			"\n\tCommnad attack you must choose a enemy ej: attack guard "
			"\n\tCommand insert is especial because use three words you must choose two items ej: insert bullets pistol ";
		WaitingMenu();
	}
	else if (INFORMATION == menu_op || INFO_03 == menu_op)
	{
		system("cls");
		cout << "\n\n\tINFORMATION\n\n";
		cout << "\n\tThis game was developes by Alejandro Matus on 2022 for an online test for UPC School."
			"\n\tFor any questions, contact or comments please send an email to alejandromatusovejero@gmail.com"
			"\n\tCopyright (C) 2007 Free Software Foundation, Inc. https://fsf.org/"
			"\n\tEveryone is permitted to copy and distribute verbatim copies"
			"\n\tof this license document, but changing it is not allowed.";
		WaitingMenu();
	}
	else if (ACHIEVEMENTS == menu_op || ACHI_04 == menu_op)
	{
		system("cls");
		cout << "\n\n\tTHE ARCHIVE TOWER\n\n";
		player->ShowAchievements();
		WaitingMenu();
	}
	else
	{
		MenuOn();
		cout << "\n\n\tIts not an menu option";
	}
}

void World::WaitingMenu()
{
	cout << "\n\n\t Press ENTER.\n";
    #ifdef __unix__
	system("read");
    #endif
	#ifdef _WIN32
	cout << "\t"; system("pause");
	#endif
	MenuOn();
}

void World::Command_action(const vector<string>& words)
{
	string cmd_01 = Txt_to_low(words.at(0));
	string cmd_02 = "";
	string cmd_03 = "";
	if (words.size() > 1)
	{
		cmd_02 = Txt_to_low(words.at(1));
		if (words.size() == 3)
		{
			cmd_03 = Txt_to_low(words.at(2));
		}
	}
	if (MENU == cmd_01) {
		MenuOn();
	}
	else if (INSERT == cmd_01)
	{
		player->InsertItem(cmd_02, cmd_03);
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
		if (cmd_02 == "outside")
		{
			cout << "\n\n\tCONGRATS YOU WIN THE GAME!!! THANKS FOR PLAYING!!!";
			WaitingMenu();
			gamefinished = true;
		}
		else
		{
			player->Go(cmd_02);
			player->GetAchievement();
		}		
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
		if (player->Attack(cmd_02) != true)
		{
			cout << "\n\n\tCONGRATS YOU BEAT THE GUARD AND WIN THE GAME!!! THANKS FOR PLAYING!!!";
			WaitingMenu();
			SetFinishGame(true);
		}
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
	return "\n\tExit to " + room->GetName() + ".";
}
