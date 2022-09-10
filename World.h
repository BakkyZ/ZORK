#include "Global.h"

#define INVENTORY "inventory"
#define LOOK "look" 
#define GO "go"
#define TAKE "take"
#define DROP "drop"
#define EQUIP "equip"
#define UNEQUIP "unequip"
#define ATTACK "attack"
#define OPEN "open"
#define EXIT "exit"
#define QUIT "quit"
#define MENU "menu"
#define HELP "help"

class World {

public:
	World();
	~World();

	void Play();
	void Command_input(const vector<string>& words);
	bool FinishGame() const;

private:

	void Command_action(const vector<string>& words);
	void Command_menu(int menu_op);
	void Help() const;
	bool gamefinished;
};
