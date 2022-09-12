#pragma once
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>
using namespace std;

enum class Path : int { CORRIDOR, CELL, YARD, RESTROOM, TOWER, GATE, ARMERY, OUTSIDE };

vector<string> Txt_split(string& str);
string Txt_to_low(string str);
string Txt_to_up(string str);
string NamePath(const Path& dir);
Path* SetPath(const string& str);
bool IsPath(const string& str);