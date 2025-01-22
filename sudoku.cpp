#include <ncurses.h>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <chrono>
#include <string>
#include "Core.h"
#include "File.h"
#include "User.h"

using namespace std;

int main(){
    initscr();
    while(true){
        printw("Please enter your name , it must be new : ");
        char name[80];
        getstr(name);
        string UserName(name);
        if(UserName == "exit") break;
        if(!AddUser(UserName)) continue;
    }
    endwin();
}
