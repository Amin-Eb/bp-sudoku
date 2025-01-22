#include <iostream>
#include <string>

using namespace std;

struct Mat{
	int table[9][9];
};
bool valid(const Mat mat);
string fixed_print(string str,int len);