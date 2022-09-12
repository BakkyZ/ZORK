#include "Global.h"
#include "World.h"

int main()
{
	World world;
	string input;
	int clean = 0;

	world.MenuOn();

	while (world.FinishGame() != true)
	{
		if (clean == 0)
		{
			cout << "\n\n\tChoose an command:\t";
		}
		else
		{
			clean = 0;
		}

		getline(cin, input);
		vector<string> command = Txt_split(input);

		if (command.empty() == true)
		{
			clean++;

			if (world.MenuStatus() == true) 
			{
				world.MenuOn();
				cout << "\n\tGive me a correct command:  ";
			}
			else
			{
				cout << "\n\tGive me a correct command:  ";
			}
		}
		else if (command.size() > 0 && (EXIT == Txt_to_low(command.at(0))) || QUIT == Txt_to_low(command.at(0)) || EXIT_05 == Txt_to_low(command.at(0)))
		{
			break;
		}
		else if (world.MenuStatus() == true)
		{
			world.Command_menu(command);
		}
		else
			world.Command_input(command);
		}

	cout << "\n\n\tSee you next time. Thanks for playing!";
	return 0;
}