#include "User.h"

using namespace std;

bool AddUser(string UserName){
    ifstream Users("users.txt");
    string  s;
    while (getline (Users, s))
        if(s == UserName) 
            return 0;
    Users.close();
    ofstream Userss("users.txt");
    Userss << UserName;
    Userss.close();
    return 1;
}
vector<string> GetLeaderBoard(){
    ifstream Users("leaderboard.txt");
    string s;
    vector<string> vc;
    while (getline (Users, s)) vc.push_back(s);
    return vc;
}