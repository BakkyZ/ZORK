#include "Global.h"
#include "World.h"
#include "menu.h"

int main() {

	//cout << "\n\n\t\tWELLCOME TO XXXX!\n\n\t1 - PLAY\n\n\t2 - HOW TO PLAY\n\n\t3 - INFO\n\n\t4 - ACHIEVEMENTS\n\n\t5 - QUIT";

	menu p_menu(1);
	World world;
	string input;
	int game_started = 0;

	world.Play();

	while (1) {

		cout << "\n\n\tChoose an accion:\t";

		getline(cin, input);
		vector<string> command = Txt_split(input);

		if (command.empty() == true) { cout << "\n\tGive me a correct command!"; }
		if (command.size() > 0 && (EXIT == Txt_to_low(command.at(0))) || QUIT == Txt_to_low(command.at(0)) || EXIT_05 == Txt_to_low(command.at(0))) { break; }
		//if (game_started == 0 || ACTION_MENU == (command.at(0))) { p_menu.title_menu(1); p_menu.menuopt(1); }
		//if (PLAY == "play" || P_01 == "1") {  } RESERVAADO PARA MENU
		//world.Play();

		world.Command_input(command);

	}

	cout << "\n\n\tSee you next time. Thanks for playing!";
	return 0;
}