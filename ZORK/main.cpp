#include "Global.h"
#include "World.h"

int main()
{
	World world;
	string input;
	world.MenuOn();
	int clean = 0;

	while (world.FinishGame() != true)
	{

		cout << "\n\tChoose an command:\t";

		getline(cin, input);
		vector<string> command = Txt_split(input);

		if (command.empty() == true)
		{
			cout << "\n\tGive me a correct command!";
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
		{
			if (clean >= 3)
			{
				clean = 0;
				system("cls");
				world.Play();
			}
			clean++;
			world.Command_input(command);
		}

	}

	cout << "\n\n\tSee you next time. Thanks for playing!";
	return 0;
}