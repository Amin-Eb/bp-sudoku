#include <ncurses.h>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <thread>
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
#include <string>
#include <random>
#include "Core.h"
#include "User.h"
#include "File.h"

using namespace std;

inline void wait ( short seconds )
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait); 
}
inline void PrintMenu(string UserName);
inline void PlaySaved(string& UserName,int& ElapsedTime,int& dif,Mat& SudokuTable, Mat& verdict,int& wrs);
void PrintScr(Mat mat,Mat mat2, int x,int y, string UserName,int t,int wrongs);
mt19937 mt(time(nullptr));  
bool is_keyboard_hit();
int nb_getch(void);   
string CLEAR_LINE = "";


int main(){
    initscr();
    noecho();
    cbreak();
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
            PrintMenu(UserName);
            ch = getch();
            if(ch == 'E') break;
            if(ch == 'L') {
                int ind = 0;
                clear();
                for(auto inst : GetLeaderBoard()){
                    attron(COLOR_PAIR(3));
                    printw("%d : ", ind + 1); ind ++;
                    attroff(COLOR_PAIR(3));
                    printw("%s in %s seconds.\n", inst.second, inst.first);
                }
                if(!ind) printw("No data found.\nplease press any key to continue...");
                refresh();
                getch();
            }
            if(ch == 'S'){
                int dif = 0, wrs = 0, elpsd = 0;
                while(true){
                    clear();
                    printw("choose dificulty (1-3) : ");
                    ch = getch();
                    if(ch != '1' && ch != '2' && ch != '3') continue;
                    dif = 180 + (3 - (ch - '0')) * 30;
                    break;
                }
                Mat SudokuTable, verdict;
                PlaySaved(UserName, elpsd, dif, SudokuTable, verdict, wrs);
            }
            if(ch == 'P'){
                clear();
                move(0,0);
                printw("Enter the username of saved game : ");
                char name[80];
                getstr(name);
                string UserName(name);
                if(!CheckUser(UserName)){
                    clear();
                    attron(COLOR_PAIR(2));
                    printw("%s\n",fixed_print("Username not found in saved games :(", COLS).c_str());
                    attroff(COLOR_PAIR(2));
                    printw("%s\n",fixed_print("press any key to continue ...",COLS).c_str());
                    refresh();
                    ch = getch();
                    break;
                }
                int elpsd, dif, wrs;
                Mat SudokuTable, verdict;
                LoadGame(UserName, elpsd, dif, SudokuTable, verdict, wrs);
                PlaySaved(UserName, elpsd, dif, SudokuTable, verdict, wrs);
            }
        }
    }
    endwin();
}

void PrintScr(Mat mat1,Mat mat2,int x,int y, string UserName,int t,int wrongs){
    clear();
    move(0, 0);
    attron(COLOR_PAIR(3));
    printw("%s\n",fixed_print("Good luck " + UserName , COLS).c_str());
    attroff(COLOR_PAIR(3));
    printw("Elapsed time : %d ' :: %d \"", t/8/60, (t/8)%60 );
    attron(COLOR_PAIR(2));
    printw("  wrong actions : %d", wrongs);
    attroff(COLOR_PAIR(2));
    int sz = COLS - 35;
    for(int k = 0; k < 9; k ++){
        move(k + 4 + k/3, sz/2);
        for(int i = 0; i < 9; i ++){
            if(k == x && i == y)attron(COLOR_PAIR(1));
            printw("[");
            attroff(COLOR_PAIR(1));
            if(mat2.table[k][i] == 2){
                attron(COLOR_PAIR(2));
                printw("%d", mat1.table[k][i]);
                attroff(COLOR_PAIR(2));
            }
            if(mat2.table[k][i] == 3){
                attron(COLOR_PAIR(3));
                printw("%d", mat1.table[k][i] );
                attroff(COLOR_PAIR(3));
            }
            if(mat2.table[k][i] == 1) printw("%d", mat1.table[k][i]);
            if(mat2.table[k][i] == 0) printw("-");
            if(k == x && i == y)attron(COLOR_PAIR(1));
            printw("]");
            if((i+1)%3 == 0) printw(" ");
            attroff(COLOR_PAIR(1));
        }
    }
    refresh();

}
bool is_keyboard_hit()
{
    static struct termios oldt, newt;
    int cnt = 0;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_iflag = 0;     // input mode
    newt.c_oflag = 0;     // output mode
    newt.c_cc[VMIN] = 1;  // minimum time to wait
    newt.c_cc[VTIME] = 1; // minimum characters to wait for
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ioctl(0, FIONREAD, &cnt); // Read count
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;
    select(STDIN_FILENO + 1, NULL, NULL, NULL, &tv); // A small time delay
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return cnt > 0;
}
int nb_getch(void)
{
    if (is_keyboard_hit())
        return getch();
    else
        return 0;
}
inline void PrintMenu(string UserName){
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
}
inline void PlaySaved(string& UserName,int& ElapsedTime,int& dif,Mat& SudokuTable, Mat& verdict,int& wrs){
    SudokuTable = ReadSudoku(1);
    int stat = 0, x = 0, y = 0, empty = 0;
    char ch;
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++) {
            verdict.table[i][j] = (SudokuTable.table[i][j] > 0);
            empty += (verdict.table[i][j] == 0);
        }
    }
    for(ElapsedTime; ElapsedTime < dif * 8; ElapsedTime ++){
        ch = nb_getch();
        if(ch == 27){
            clear();
            move(0, 0);
            printw(fixed_print("You stoped the game, press Esc for continue ... ",COLS).c_str());
            refresh();
            ch = 0;
            while(ch != 27){
                ch = getch();
            }
        }
        if(ch == 'S'){
            SaveGame(UserName, ElapsedTime, dif,SudokuTable, verdict, wrs);
            clear();
            attron(COLOR_PAIR(3));
            printw("%s\n",fixed_print("Game Saved :)", COLS).c_str());
            attroff(COLOR_PAIR(3));
            printw("%s\n",fixed_print("press any key to continue ...",COLS).c_str());
            refresh();
            ch = getch();
        }
        if(ch == 'd')
            y ++, y = min(y, 8);
        if(ch == 'a')
            y --, y = max(y, 0);
        if(ch == 'w')
            x --, x = max(x, 0);
        if(ch == 's')
            x ++, x = min(x, 8);
        if(verdict.table[x][y] == 1) {
            PrintScr(SudokuTable, verdict, x, y, UserName, ElapsedTime, wrs);
            std::this_thread::sleep_for(std::chrono::milliseconds(125));              
            continue;
        }
        if('0' < ch && ch <= '9'){
            SudokuTable.table[x][y] = ch - '0';
            verdict.table[x][y] = 3;
            empty --;
            if(!valid(SudokuTable)) wrs ++, verdict.table[x][y] = 2, empty ++;
        }
        if(ch == '-'){
            SudokuTable.table[x][y] = 0;
            verdict.table[x][y] = 0;
            empty ++;
        }
        if(wrs == 5) break;
        if(empty == 0){
            stat = 1;
            PrintScr(SudokuTable, verdict, x, y, UserName, ElapsedTime, wrs);
            move(20,0);
            printw("%s\n\n",fixed_print("*** OMG YOU WON!! ***", COLS).c_str());
            printw("%s", fixed_print("press any key to continue..", COLS).c_str());
            refresh();
            getch();
            AddLeaderBoard(UserName, ElapsedTime/8);
            return;
        }
        PrintScr(SudokuTable, verdict, x, y, UserName, ElapsedTime, wrs);
        std::this_thread::sleep_for(std::chrono::milliseconds(125));              
    }
    clear();
    attron(COLOR_PAIR(2));
    printw("%s\n",fixed_print("Ah shit, maybe next time you can solve this simple thing.", COLS).c_str());
    attroff(COLOR_PAIR(2));
    printw("%s\n",fixed_print("press any key to continue ...",COLS).c_str());
    refresh();
    ch = getch();
}