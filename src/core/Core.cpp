#include "Core.h"

using namespace std;

bool valid(const Mat mat){
	for(int i = 0; i < 9; i ++){
		bool seen[10];
		fill(seen, seen+10, 0);
		for(int j =0; j < 9; j ++){
			if(seen[mat.table[i][j]]) return 0;
			seen[mat.table[i][j]] = 1;
		}
	}
	for(int i = 0; i < 9; i ++){
		bool seen[10];
		fill(seen, seen+10, 0);
		for(int j =0; j < 9; j ++){
			if(seen[mat.table[j][i]]) return 0;
			seen[mat.table[j][i]] = 1;
		}
	}
	return 1;
}