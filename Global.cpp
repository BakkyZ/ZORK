#include "Global.h"

vector<string> Txt_split(string& str) {
	vector<string> txt_01;
	size_t a = 0;
	string txt_02;

	if (!str.empty()) {

		while ((a = str.find(" ")) != string::npos) {
			txt_02 = str.substr(0, a);
			txt_01.push_back(txt_02);
			str.erase(0, a + 1);
		}
		if (!str.empty()) { txt_01.push_back(str); }
	}
	return txt_01;
}


string Txt_to_low(string str) {
	transform(str.begin(), str.end(), str.begin(), tolower);
	return str;
}

string Txt_to_up(string str) {
	transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

string NamePath(const Path& dir) {
	string place = nullptr;

	switch (dir) {
	case CELL:
		place = "cell";
		break;
	case CORRIDOR:
		place = "corridor";
		break;
	case YARD:
		place = "yard";
		break;
	default:
		break;

		return place;
	}
}

Path* SetPath(const string& str) {
	Path* place = nullptr;

	if (str.compare("cell") == 0)
		place = new Path(Path::CORRIDOR);
	else if (str.compare("corridor") == 0)
		place = new Path(Path::CELL);
	else if (str.compare("yard") == 0)
		place = new Path(Path::YARD);

	return place;
}

bool IsPath(const string& str) { return SetPath(str) != nullptr; }

