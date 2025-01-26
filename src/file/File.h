#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "../core/Core.h"

using namespace std;

Mat ReadSudoku(int n);
void SaveGame(string username, int t, int dif,Mat mat1, Mat mat2,int wrs);
void LoadGame(string& username, int& t, int& dif,Mat& mat1, Mat& mat2,int& wrs);