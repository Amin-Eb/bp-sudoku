#include "File.h"

using namespace std;

int strtoint_(string s){
	int ret = 0;
	for(auto ch : s){
		ret *= 10;
		ret +=ch - '0';
	}
	return ret;
}
Mat ReadSudoku(string FileName){
    Mat ret;
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

void SaveGame(string username, int t, int dif,Mat mat1, Mat mat2,int wrs){
    ofstream username_f("SavedGames/Usernames.txt", std::ios_base::app);
    username_f << username << endl;
    username_f.close();

    ofstream t_f("SavedGames/" + username + "_time.txt");
    t_f << t;
    t_f.close();
    
    ofstream dif_f("SavedGames/" + username + "_dif.txt");
    dif_f << dif;
    dif_f.close();

    ofstream wrs_f("SavedGames/" + username + "_wrs.txt");
    wrs_f << wrs;
    wrs_f.close();

    ofstream mat1_f("SavedGames/" + username + "_mat1.txt");
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++)
            mat1_f << mat1.table[i][j] << " ";
        mat1_f << endl;
    }
    mat1_f.close();

    ofstream mat2_f("SavedGames/" + username + "_mat2.txt");
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++)
            mat2_f << mat2.table[i][j] << " ";
        mat2_f << endl;
    }
    mat2_f.close();
}
void LoadGame(string& username, int& t, int& dif,Mat& mat1, Mat& mat2,int& wrs){
    string s;

    ifstream t_f("SavedGames/" + username + "_time.txt");
    while (getline (t_f, s))
        t = strtoint_(s);
    t_f.close();
    
    ifstream dif_f("SavedGames/" + username + "_dif.txt");
    while (getline (dif_f, s))
        dif = strtoint_(s);
    dif_f.close();
    
    ifstream wrs_f("SavedGames/" + username + "_wrs.txt");
    while (getline (wrs_f, s))
        wrs = strtoint_(s);
    wrs_f.close();

    mat1 = ReadSudoku("SavedGames/" + username + "_mat1.txt");

    mat2 = ReadSudoku("SavedGames/" + username + "_mat2.txt");
}