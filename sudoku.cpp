#include <ncurses.h>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <vector>
#include <chrono>
#include <string>
#include <random>
#include "Core.h"
#include "File.h"
#include "User.h"

using namespace std;

void PrintScr(Mat mat,Mat mat2, int x,int y, string UserName,int t);
mt19937 mt(time(nullptr));  

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
        while(true){
            clear();   
            attron(COLOR_PAIR(3));
            move(0,0);
            printw("%s", CLEAR_LINE.c_str());
            move(0,0);
            printw(fixed_print("^_^ sudoku ^_^",COLS).c_str());
            refresh();
            attroff(COLOR_PAIR(3));
            attron(COLOR_PAIR(1));
            move(3,0);
            printw("%s\n", fixed_print("Hello " +UserName, COLS).c_str());
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
            if(ch == 'E') break;
            if(ch == 'L') {
                int ind = 0;
                clear();
                for(auto UserName : GetLeaderBoard()){
                    attron(COLOR_PAIR(3));
                    printw("%d : ", ind); ind ++;
                    attroff(COLOR_PAIR(3));
                    printw("%s\n", UserName);
                }
                if(!ind) printw("No data found.\nplease press any key to continue...");
                refresh();
                getch();
            }
            if(ch == 'S'){
                int dif = 0;
                while(true){
                    clear();
                    printw("choose dificulty (1-3) : ");
                    ch = getch();
                    if(ch != '1' && ch != '2' && ch != '3') continue;
                    dif = ch - '0';
                    break;
                }
                Mat SudokuTable = ReadSudoku(1);
                Mat verdict;
                for(int i = 0; i < 9; i ++)
                    for(int j = 0; j < 9; j ++) verdict.table[i][j] = (SudokuTable.table[i][j] > 0);
                
                    
            }
        }
    }
    endwin();
}

void PrintScr(Mat mat1,Mat mat2,int x,int y, string UserName,int t){
    move(0, 0);
    //printw(fixed_print("Good luck " + UserName , COLS).c_str());
    printw("%d", t);
    refresh();
    getch();
    int sz = COLS - 35;
    move(3 , sz/2);
    for(int i = 0 ; i < 9; i ++){
        for(int j = 0; j < 9; j ++){

        }
    }
}