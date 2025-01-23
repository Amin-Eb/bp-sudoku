#include "File.h"

using namespace std;

Mat ReadSudoku(int n){
    Mat ret;
    string FileName = "s";
    FileName += (char)(n + '0');
    FileName += ".txt";
    ifstream Users(FileName);
    string  s;
    int ind = 0;
    while (getline (Users, s)){
        for(int i = 0; i < 9; i ++)
            ret.table[ind][i] = s[i*2] - '0';
        ind ++;
    }
    return ret;
}