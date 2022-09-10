#pragma once
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>
using namespace std;

enum Path { CORRIDOR, CELL, YARD, RESTROOM, TOWER, FOUNTAIN, GATE, RUFT };

vector<string> Txt_split(string& str);
string Txt_to_low(string str);
string Txt_to_up(string str);
string NamePath(const Path& dir);
Path* SetPath(const string& str);
bool IsPath(const string& str);