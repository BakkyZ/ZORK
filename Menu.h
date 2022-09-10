#define PLAY "play"
#define P_01 "1"
#define HOW PLAY "how"
#define INFO_02 "2"
#define INFORMATION "information"
#define INFO_03 "3"
#define ACHIEVEMENTS "achivements"
#define ACHI_04 "0"
#define EXIT_05 "5"

class menu
{
public:

	menu(int id_menu);
	void menuopt(int x);
	void title_menu(int id);

private:

	bool menu_status;

};
