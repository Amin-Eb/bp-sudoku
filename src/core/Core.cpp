#include "Core.h"

using namespace std;

bool valid(const Mat mat){
	for(int i = 0; i < 9; i ++){
		bool seen[10];
		fill(seen, seen+10, 0);
		for(int j =0; j < 9; j ++){
			if(mat.table[i][j]==0) continue;
			if(seen[mat.table[i][j]]) return 0;
			seen[mat.table[i][j]] = 1;
		}
	}
	for(int i = 0; i < 9; i ++){
		bool seen[10];
		fill(seen, seen+10, 0);
		for(int j =0; j < 9; j ++){
			if(mat.table[j][i]==0) continue;
			if(seen[mat.table[j][i]]) return 0;
			seen[mat.table[j][i]] = 1;
		}
	}
	return 1;
}

string fixed_print(string str,int len){
    int sz = len - str.size();
    for(int i = 0; i < sz/2; i ++) str = " " + str;
	for(int i = 0; i < sz/2; i ++) str = str + " ";
	return str; 
}

int stoint(string s){
	int ret = 0;
	for(auto ch : s){
		ret *= 10;
		ret +=ch - '0';
	}
	return ret;
}