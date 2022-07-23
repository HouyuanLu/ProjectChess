#include <iostream>
#include <random>
using namespace std;
#ifndef PROJECTCHESS_FUNCTIONS_H
#define PROJECTCHESS_FUNCTIONS_H
#define CB 25
#define CB1 26
#define CEN 13
int REMX1 = 0;
int REMY1 = 0;
int REMX = 0;
int REMY = 0;
int usedx, usedy;
int px,py;
int stepsq = 0;
int steps = 0;
int MAINMODE;
int tmpi = 0;
int tmpii = 0;
int rectmp = 0;
int rectmp1 = 0;
int rectmp2 = 0;
int steppedx = 0;
int steppedy = 0;
string map[CB1][CB1];
int vis[CB1][CB1];
bool DECouldvis[CB1][CB1];
bool DECouldvis1[CB1][CB1];
bool couldVis[CB1][CB1];
bool couldVis1[CB1][CB1];
bool couldVis2[CB1][CB1];
bool finished = false;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
inline void help(){
    cout << "Welcome to the help utility" << endl;
    cout << "Do you want to continue? (1: Yes/ 2: No): ";
    int tmpa;
    cin >> tmpa;
    if(tmpa == 2){
        return;
    }
    if(tmpa == 1){
        while(true){
            cout <<"0. Exit" << endl;
            cout <<"1. Basic Inputs" << endl;
            cout <<"2. Game Rules" << endl;
            cout <<"Enter Your Choice: " << endl;
            int tmpb;
            cin >> tmpb;
            if(tmpb == 0){
                return;
            }
            if(tmpb == 1){
                cout << "To place a piece on the board, enter the exact position." << endl;
                cout << "Note: Enter the row you want to place the piece first, then enter the column."
                     << endl;
                cout << "EXP: If you want to place on the second row in the third column, type this '2 3'."
                     << endl;
                cout << endl;
            }
            if(tmpb == 2){
                cout << "The rule of this game is simple: " << endl;
                cout << "The first one that can connect FIVE pieces together wins.";
                cout << "Note: The pieces are connected when ALL of the pieces are on the same row/column or "
                        "if they are connected diagonally. " <<endl;
                cout << endl;
            }
        }
    }
}
inline void reset(){
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= CB; i++) {
        if(i == 0){
            continue;
        }
        cnt1++;
        map[0][i] = to_string(cnt1);
    }
    for (int i = 0; i <= CB; i++) {
        if(i == 0){
            continue;
        }
        cnt2++;
        map[i][0] = to_string(cnt2);
    }
    map[0][0] = "0";
    for (int i = 1; i <= CB; i++) {
        for (int j = 1; j <= CB; j++) {
            if(map[i][j] == "1" || map[i][j] == "2"){
                continue;
            }
            if(i==1&&j==1){
                map[i][j] = "©°";
                continue;
            }
            if(i==1&&j==CB){
                map[i][j] = "©´";
                continue;
            }
            if(i == 1&&j>1&& j<CB){
                map[i][j] = "©Ð";
                continue;
            }
            if(j == 1&&i>1&&i<CB){
                map[i][j] = "©À";
                continue;
            }
            if(j == CB&&i>1&&i<CB){
                map[i][j] = "©È";
                continue;
            }
            if(i == CB && j == 1){
                map[i][j] = "©¸";
                continue;
            }
            if(j == CB && i == CB){
                map[i][j] = "©¼";
                continue;
            }
            if(i == CB&&j>1&&j<CB){
                map[i][j] = "©Ø";
                continue;
            }
            map[i][j] = "©à";
        }
    }
}
inline void print(){
    if(MAINMODE == 2){
        bool kk = false;
        for(int i = 0; i<=CB; i++){
            for(int j = 0; j<=CB; j++){
                if(i == 0&&map[i][j]>="10" && map[i][j] <=to_string(CB)){
                    cout << map[i][j] << " ";
                    kk = true;
                }
                if(j == 0&&map[i][j] >="10" && map[i][j]<=to_string(CB)){
                    cout << map[i][j] << " ";
                    kk = true;
                }
                if(steppedx == i&&steppedy == j){
                    if(steppedx == CEN && steppedy == CEN){
                        cout << "1" << " " << " ";
                        kk = true;
                    }else{
                        cout << "A" << " " << " ";
                        kk = true;
                    }
                }
                if(!kk){
                    cout << map[i][j] << " " << " ";
                }
                if(j == 0&&map[i][j] >="0" && map[i][j]<="9"){
                    cout << " ";
                }
                if(j == 0&&map[i][j] == "2"){
                    cout << " ";
                }
                if(i == 0&&map[i][j] == "2"){
                    cout << " ";
                }
                kk = false;
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    bool kk = false;
    for(int i = 0; i<=CB; i++){
        for(int j = 0; j<=CB; j++){
            if(i == 0&&map[i][j]>="10" && map[i][j] <=to_string(CB)){
                cout << map[i][j] << " ";
                kk = true;
            }
            if(j == 0&&map[i][j] >="10" && map[i][j]<=to_string(CB)){
                cout << map[i][j] << " ";
                kk = true;
            }
            if(steppedx == i&&steppedy == j){
                if(steppedx == CEN && steppedy == CEN){
                    cout << "1" << " " << " ";
                    kk = true;
                }else{
                    cout << "A" << " " << " ";
                    kk = true;
                }
            }
            if(!kk){
                cout << map[i][j] << " " << " ";
            }
            if(j == 0&&map[i][j] >="0" && map[i][j]<="9"){
                cout << " ";
            }
            if(j == 0&&map[i][j] == "2"){
                cout << " ";
            }
            if(i == 0&&map[i][j] == "2"){
                cout << " ";
            }
            kk = false;
        }
        cout << endl;
    }
    cout << endl;
    if(stepsq == 0){
        steppedx = CEN;
        steppedy = CEN;
        stepsq++;
    }
    cout << "Computer has chosen:" << " "<< steppedx <<" "<< "and"<<" "<< steppedy << endl;
    stepsq++;
}
inline int random() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> d(0,7);
    return d(gen);
}
inline void retreat(int M){
    if(M == 2){
        vis[REMX][REMY] = 0;
        map[REMX][REMY] = "0";
        reset();
        print();
    }else{
        vis[REMX1][REMY1] = 0;
        map[REMX1][REMY1] = "0";
        reset();
        print();
    }
}

#endif //PROJECTCHESS_FUNCTIONS_H
