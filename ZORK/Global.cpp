#include "Global.h"

vector<string> Txt_split(string& str)
{
	vector<string> txt_01;
	size_t a = 0;
	string txt_02;

	if (!str.empty())
	{
		while ((a = str.find(" ")) != string::npos)
		{
			txt_02 = str.substr(0, a);
			txt_01.push_back(txt_02);
			str.erase(0, a + 1);
		}
		if (!str.empty())
		{
			txt_01.push_back(str);
		}
	}
	return txt_01;
}


string Txt_to_low(string str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
	return str;
}

string Txt_to_up(string str)
{
	transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

string NamePath(const Path& dir)
{
	string place = "nullptr";

	switch (dir)
	{
	case Path::CELL:
		place = "cell";
		break;
	case Path::CORRIDOR:
		place = "corridor";
		break;
	case Path::YARD:
		place = "yard";
		break;
	case Path::TOWER:
		place = "tower";
		break;
	case Path::GATE:
		place = "gate";
		break;
	case Path::RESTROOM:
		place = "restroom";
		break;
	case Path::ARMERY:
		place = "armery";
		break;
	case Path::OUTSIDE:
		place = "outside";
		break;
	default:
		break;
	}
	return place;
}

Path* SetPath(const string& str)
{
	Path* place = nullptr;

	if (str.compare("cell") == 0)
	{
		place = new Path(Path::CELL);
	}
	else if (str.compare("corridor") == 0)
	{
		place = new Path(Path::CORRIDOR);
	}
	else if (str.compare("yard") == 0)
	{
		place = new Path(Path::YARD);
	}
	else if (str.compare("restroom") == 0)
	{
		place = new Path(Path::RESTROOM);
	}
	else if (str.compare("gate") == 0)
	{
		place = new Path(Path::GATE);
	}
	else if (str.compare("tower") == 0)
	{
		place = new Path(Path::TOWER);
	}
	else if (str.compare("armery") == 0)
	{
		place = new Path(Path::ARMERY);
	}
	else if (str.compare("outside") == 0)
	{
		place = new Path(Path::OUTSIDE);
	}

	return place;
}

bool IsPath(const string& str)
{
	return SetPath(str) != nullptr;
}


