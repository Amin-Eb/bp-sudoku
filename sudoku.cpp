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
    noecho();
    cbreak();
    string CLEAR_LINE = "";
    for(int i = 0; i < COLS; i ++) CLEAR_LINE += " ";
    start_color();
    init_pair(1,COLOR_YELLOW, 0);
    init_pair(2,COLOR_RED, 0);
    init_pair(3,COLOR_GREEN, 0);
    init_pair(4,COLOR_BLUE, 0);

    char ch;

    while(true){

        clear();
        printw("Please enter your name , it must be new , (exit for exit!) : ");
        refresh();
        char name[80];
        getstr(name);
        string UserName(name);
        if(UserName == "exit") break;
        if(!AddUser(UserName)) continue;

        attron(COLOR_PAIR(3));
        move(0,0);
        printw("%s", CLEAR_LINE.c_str());
        move(0,0);
        printw(fixed_print("^_^ sudoku ^_^",COLS).c_str());
        refresh();
        attroff(COLOR_PAIR(3));
        attron(COLOR_PAIR(1));
        move(3,0);
        printw("%s", fixed_print("Hello " +UserName, COLS).c_str());
        refresh();
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        printw("(S)tart a new game\n");
        printw("(P)lay a saved game\n");
        printw("(L)eaderboard\n");
        printw("(E)xit the game\n");
        refresh();
        attroff(COLOR_PAIR(2));
        ch = getch();
        if(ch == 'E') exit(0);
    }
    endwin();
}
