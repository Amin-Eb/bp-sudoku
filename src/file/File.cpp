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

void SaveGame(string username, int t, int dif,Mat mat1, Mat mat2,int wrs){
    ofstream username_f("SavedGames/Usernames.txt");
    username_f << username << endl;
    username_f.close();

    ofstream t_f("SavedGames/" + username + "_time.txt");
    t_f << t;
    t_f.close();
    
    ofstream dif_f("SavedGames/" + username + "_dif.txt");
    dif_f << dif;
    dif_f.close();

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

}