#include "User.h"

using namespace std;

pair<string, string> parser(string s){
    string ret1 = "", ret2 = "";
    int i = 0;
    for(i; s[i]!=','; i ++) ret1 += s [i];
    i ++;
    for(i; i < s.size(); i ++) ret2 += s[i];
    return {ret1, ret2};
}
bool AddUser(string UserName){
    ifstream Users("users.txt");
    string  s;
    while (getline (Users, s))
        if(s == UserName) {
            Users.close();
            return 0;
        }
    Users.close();
    ofstream Userss("users.txt");
    Userss << UserName;
    Userss.close();
    return 1;
}
bool CheckUser(string UserName){
    ifstream Users("SavedGames/Usernames.txt");
    string  s;
    while (getline (Users, s))
        if(s == UserName) {
            Users.close();
            return 1;
        }
    Users.close();
    return 0;
}
vector<pair<string,string>> GetLeaderBoard(){
    ifstream Users("leaderboard.txt");
    string s;
    vector<pair<string,string>> vc;
    while (getline (Users, s)) vc.push_back(parser(s));
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());
    Users.close();
    return vc;
}
void AddLeaderBoard(string username,int t){
    ofstream Users("leaderboard.txt");
    Users << (to_string(t) + "," + username);
    Users.close();
}