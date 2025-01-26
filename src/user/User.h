#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool AddUser(string UserName);
bool CheckUser(string UserName);
pair<string, string> parser(string s);
vector<pair<string, string>> GetLeaderBoard();
void AddLeaderBoard(string username, int t);