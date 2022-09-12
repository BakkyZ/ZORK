#include "Global.h"
#include "Entity.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Enemy.h"
#include "Achievements.h"

#define INVENTORY "inventory"
#define LOOK "look" 
#define GO "go"
#define TAKE "take"
#define DROP "drop"
#define EQUIP "equip"
#define UNEQUIP "unequip"
#define ATTACK "attack"
#define OPEN "open"
#define INSERT "insert"
#define EXIT "exit"
#define QUIT "quit"
#define MENU "menu"
#define HELP "help"
#define PLAY "play"
#define P_01 "1"
#define HOW PLAY "how"
#define INFO_02 "2"
#define INFORMATION "information"
#define INFO_03 "3"
#define ACHIEVEMENTS "achivements"
#define ACHI_04 "4"
#define EXIT_05 "5"

class World
{

public:
	World();
	~World();

	void Play();
	void MenuOn();
	void Command_input(const vector<string>& words);
	bool FinishGame() const;
	void SetFinishGame(bool status);
	bool MenuStatus() const;
	void SetMenu(bool status);
	void Command_menu(const vector<string>& words);

private:
	void Command_action(const vector<string>& words);
	void WaitingMenu();
	string ExitName(Room* room) const;
	Player* player;
	vector<Entity*> entity;
	bool gamefinished;
	bool menu_status = true;
};
