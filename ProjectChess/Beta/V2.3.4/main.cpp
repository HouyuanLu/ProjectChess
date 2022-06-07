#include <iostream>
#include <random>
#include <string>
#define CB 25
#define CB1 26
#define CEN 13
using namespace std;
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
/*h214N*/
//todo: BUG: Attack problem
//todo: NEEDED: Defend Couldvis

/* Sub Functions */
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
        map[0][i] = to_string(cnt1);
        cnt1++;
    }
    for (int i = 0; i <= CB; i++) {
        map[i][0] = to_string(cnt2);
        cnt2++;
    }
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
void retreat(int M){
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
/* Attack Functions */
int checkAI(int x, int y, int way) {
    int m = -1;
    if (way == tmpi) {
        return 200;
    }
    int tmpans = 0;
    int x1, y1, x11, y11;
    x1 = x11 = x;
    y1 = y11 = y;
    for (int i = 1; i < 6; i++) {
        if (x1 >= 1 && y1 >= 1 && x1 <= CB && y1 <= CB) {
            x1 += dx[way];
            y1 += dy[way];
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 0) {
                if (tmpans >= 3) {
                    couldVis[x1][y1] = true;
                    int xxx = x1, yyy = y1;
                    for (int j = 1; j < 6; j++) {
                        if (xxx >= 1 && yyy >= 1 && xxx <= CB && yyy <= CB) {
                            xxx -= dx[way];
                            yyy -= dy[way];
                            if (vis[xxx][yyy] == 1) {
                                continue;
                            }
                            if (vis[xxx][yyy] == 2) {
                                break;
                            }
                            if (vis[xxx][yyy] == 0) {
                                couldVis[xxx][yyy] = true;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 2) {
                return 300;
            }
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 1) {
                tmpans++;
            } else {
                if (tmpans == 0) {
                    break;
                }
            }
        }
    }
    if (tmpans > m && tmpans > 0) {
        m = tmpans;
        rectmp1 = 1;
    }
    tmpans = 0;
    for (int i = 1; i < 6; i++) {
        if (x11 >= 1 && y11 >= 1 && x11 <= CB && y11 <= CB) {
            x11 -= dx[way];
            y11 -= dy[way];
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                if (tmpans >= 3) {
                    couldVis[x11][y11] = true;
                    int xxx = x11, yyy = y11;
                    for (int j = 1; j < 6; j++) {
                        if (xxx >= 1 && yyy >= 1 && xxx <= CB && yyy <= CB) {
                            xxx += dx[way];
                            yyy += dy[way];
                            if (vis[xxx][yyy] == 1) {
                                continue;
                            }
                            if (vis[xxx][yyy] == 2) {
                                break;
                            }
                            if (vis[xxx][yyy] == 0) {
                                couldVis[xxx][yyy] = true;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                return 300;
            }
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                tmpans++;
            } else {
                if (tmpans == 0) {
                    tmpans = 0;
                    break;
                }
            }
        }
    }
    if (tmpans > m && tmpans > 0) {
        m = tmpans;
        rectmp1 = -1;
    }
    return m;
}
int checkAI(int x, int y) {
    int m = -1;
    int tmpans = 0;
    int xx = x;
    int yy = y;
    int x1, y1, x11, y11;
    x1 = x11 = x;
    y1 = y11 = y;
    for (int i = 0; i < 8; i++) {
        int xx1 = xx + dx[i];
        int yy1 = yy + dy[i];
        if (xx1 > 0 && yy1 > 0 && xx1 <= CB && yy1 <= CB && vis[xx1][yy1] == 1) {
            tmpi = i;
            break;
        }
    }
    for (int i = 1; i < 6; i++) {
        if (x1 >= 1 && y1 >= 1 && x1 <= CB && y1 <= CB) {
            x1 += dx[tmpi];
            y1 += dy[tmpi];
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 0) {
                if (tmpans >= 3) {
                    couldVis[x1][y1] = true;
                    int xxx = x1, yyy = y1;
                    for (int j = 1; j < 6; j++) {
                        if (xxx >= 1 && yyy >= 1 && xxx <= CB && yyy <= CB) {
                            xxx -= dx[tmpi];
                            yyy -= dy[tmpi];
                            if (vis[xxx][yyy] == 1) {
                                continue;
                            }
                            if (vis[xxx][yyy] == 2) {
                                break;
                            }
                            if (vis[xxx][yyy] == 0) {
                                couldVis[xxx][yyy] = true;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 2) {
                break;
            }
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 1) {
                tmpans++;
            } else {
                if (tmpans == 0) {
                    tmpans = 0;
                    break;
                }
            }
        }
    }
    if (tmpans > m && tmpans > 0) {
        m = tmpans;
        rectmp = 1;
    }
    tmpans = 0;
    for (int i = 1; i < 6; i++) {
        if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
            x11 -= dx[tmpi];
            y11 -= dy[tmpi];
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                if (tmpans >= 3) {
                    couldVis[x11][y11] = true;
                    int xxx = x11, yyy = y11;
                    for (int j = 1; j < 6; j++) {
                        if (xxx >= 1 && yyy >= 1 && xxx <= CB && yyy <= CB) {
                            xxx += dx[tmpi];
                            yyy += dy[tmpi];
                            if (vis[xxx][yyy] == 1) {
                                continue;
                            }
                            if (vis[xxx][yyy] == 2) {
                                break;
                            }
                            if (vis[xxx][yyy] == 0) {
                                couldVis[xxx][yyy] = true;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                break;
            }
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                tmpans++;
            } else {
                if (tmpans == 0) {
                    break;
                }
            }
        }
        if (tmpans > m && tmpans > 0) {
            m = tmpans;
            rectmp = -1;
        }
    }
    return m;
}
void checkVIS(int MIN_LENGTH,int MODE) {
    if (MODE == 1) {
        int cnt;
        int cnt1;
        for (int i = 1; i <= CB; i++) {
            for (int j = 1; j <= CB; j++) {
                if (vis[i][j] == 0) {
                    continue;
                }
                if (vis[i][j] == 2) {
                    continue;
                }
                if (vis[i][j] == 1) {
                    int visway;
                    int rowtmp;
                    bool leaveflag = false;
                    for (int i1 = 0; i1 < 8; i1++) {
                        rowtmp = checkAI(i, j, i1);
                        if (rowtmp >= MIN_LENGTH) {
                            cnt = 0;
                            cnt1 = 0;
                            visway = i1;
                            int xx = i;
                            int yy = j;
                            for (int i2 = 1; i2 < 6; i2++) {
                                if (rectmp1 == 1) {
                                    if (xx >= 1 && yy >= 1 && xx <= CB && yy <= CB) {
                                        xx += dx[visway];
                                        yy += dy[visway];
                                        if (xx <= CB && yy <= CB && xx >= 1 && yy >= 1) {
                                            if (vis[xx][yy] == 1) {
                                                cnt++;
                                                continue;
                                            }
                                            if (vis[xx][yy] == 2) {
                                                break;
                                            }
                                            if (vis[xx][yy] == 0) {
                                                if (cnt >= MIN_LENGTH) {
                                                    couldVis[xx][yy] = true;
                                                    break;
                                                }
                                            }
                                        } else {
                                            leaveflag = true;
                                            break;
                                        }
                                    }
                                }
                                if (rectmp1 == -1) {
                                    if (xx <= CB && yy <= CB && xx >= 1 && yy >= 1) {
                                        xx -= dx[visway];
                                        yy -= dy[visway];
                                        if (xx <= CB && yy <= CB && xx >= 1 && yy >= 1) {
                                            if (vis[xx][yy] == 1) {
                                                cnt1++;
                                                continue;
                                            }
                                            if (vis[xx][yy] == 2) {
                                                break;
                                            }
                                            if (vis[xx][yy] == 0) {
                                                if (cnt1 >= MIN_LENGTH) {
                                                    couldVis[xx][yy] = true;
                                                    break;
                                                }
                                            }
                                        } else {
                                            leaveflag = true;
                                            break;
                                        }
                                    }
                                }
                            }
                            if (leaveflag) {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (MODE == 2) {
        int cnt;
        int cnt1;
        for (int i = 1; i <= CB; i++) {
            for (int j = 1; j <= CB; j++) {
                if (vis[i][j] == 0) {
                    continue;
                }
                if (vis[i][j] == 2) {
                    continue;
                }
                if (vis[i][j] == 1) {
                    int visway;
                    int rowtmp;
                    bool leaveflag = false;
                    for (int i1 = 0; i1 < 8; i1++) {
                        rowtmp = checkAI(i, j, i1);
                        if (rowtmp >= MIN_LENGTH) {
                            cnt = 0;
                            cnt1 = 0;
                            visway = i1;
                            int xx = i;
                            int yy = j;
                            for (int i2 = 1; i2 < 6; i2++) {
                                if (rectmp1 == 1) {
                                    if (xx >= 1 && yy >= 1 && xx <= CB && yy <= CB) {
                                        xx += dx[visway];
                                        yy += dy[visway];
                                        if (xx <= CB && yy <= CB && xx >= 1 && yy >= 1) {
                                            if (vis[xx][yy] == 1) {
                                                cnt++;
                                                continue;
                                            }
                                            if (vis[xx][yy] == 2) {
                                                break;
                                            }
                                            if (vis[xx][yy] == 0) {
                                                if (cnt >= MIN_LENGTH) {
                                                    couldVis1[xx][yy] = true;
                                                    break;
                                                }
                                            }
                                        } else {
                                            leaveflag = true;
                                            break;
                                        }
                                    }
                                }
                                if (rectmp1 == -1) {
                                    if (xx <= CB && yy <= CB && xx >= 1 && yy >= 1) {
                                        xx -= dx[visway];
                                        yy -= dy[visway];
                                        if (xx >= 1 && yy >= 1 && xx <= CB && yy <= CB) {
                                            if (vis[xx][yy] == 1) {
                                                cnt1++;
                                                continue;
                                            }
                                            if (vis[xx][yy] == 2) {
                                                break;
                                            }
                                            if (vis[xx][yy] == 0) {
                                                if (cnt1 >= MIN_LENGTH) {
                                                    couldVis1[xx][yy] = true;
                                                    break;
                                                }
                                            }
                                        } else {
                                            leaveflag = true;
                                            break;
                                        }
                                    }
                                }
                            }
                            if (leaveflag) {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (MODE == 3) {
        for (int i = 1; i <= CB; i++) {
            for (int j = 1; j <= CB; j++) {
                if (vis[i][j] == 0) {
                    continue;
                }
                if (vis[i][j] == 2) {
                    continue;
                }
                if (vis[i][j] == 1) {
                    int visway;
                    int rowtmp;
                    bool leaveflag = false;
                    for (int i1 = 0; i1 < 8; i1++) {
                        rowtmp = checkAI(i, j, i1);
                        if (rowtmp >= MIN_LENGTH) {
                            visway = i1;
                            int xx = i;
                            int yy = j;
                            for (int i2 = 1; i2 < 6; i2++) {
                                if (rectmp1 == 1) {
                                    if (xx >= 1 && yy >= 1 && xx <= CB && yy <= CB) {
                                        xx += dx[visway];
                                        yy += dy[visway];
                                        if (xx <= CB && yy <= CB && xx >= 1 && yy >= 1) {
                                            if (vis[xx][yy] == 1) {
                                                continue;
                                            }
                                            if (vis[xx][yy] == 2) {
                                                break;
                                            }
                                            if (vis[xx][yy] == 0) {
                                                couldVis2[xx][yy] = true;
                                                break;
                                            }
                                        } else {
                                            leaveflag = true;
                                            break;
                                        }
                                    }
                                }
                                if (rectmp1 == -1) {
                                    if (xx <= CB && yy <= CB && xx >= 1 && yy >= 1) {
                                        xx -= dx[visway];
                                        yy -= dy[visway];
                                        if (xx >= 1 && yy >= 1 && xx <= CB && yy <= CB) {
                                            if (vis[xx][yy] == 1) {
                                                continue;
                                            }
                                            if (vis[xx][yy] == 2) {
                                                break;
                                            }
                                            if (vis[xx][yy] == 0) {
                                                couldVis2[xx][yy] = true;
                                                break;
                                            }
                                        } else {
                                            leaveflag = true;
                                            break;
                                        }
                                    }
                                }
                            }
                            if (leaveflag) {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
void attack(int x, int y, int MIN_LENGTH) {
    if(MIN_LENGTH == 3){
        checkVIS(MIN_LENGTH, 1);
    }else if(MIN_LENGTH == 2){
        checkVIS(MIN_LENGTH,2);
    }
    int checktmp = checkAI(x, y);
    if (checktmp == 4) {
        cout << "AI HAS WON" << "!" << endl;
        system("pause");
        exit(0);
    }
    if (checktmp >= 1 && checktmp <= 3) {
        if (rectmp == 1) {
            int x1 = x + dx[tmpi];
            int y1 = y + dy[tmpi];
            while (true) {
                if (x1 >= 1 && y1 >= 1 && x1 <= CB && y1 <= CB) {
                    if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 2) {
                        int x11 = x1 - dx[tmpi];
                        int y11 = y1 - dy[tmpi];
                        while (true) {
                            if (x11 >= 1 && y11 >= 1 && x11 <= CB && y11 <= CB) {
                                if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                                    break;
                                }
                                if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                                    x11 = x11 - dx[tmpi];
                                    y11 = y11 - dy[tmpi];
                                    continue;
                                }
                                if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                                    vis[x11][y11] = 1;
                                    map[x11][y11] = "1";
                                    usedx = x11;
                                    usedy = y11;
                                    steppedx = x11;
                                    steppedy = y11;
                                    finished = true;
                                    return;
                                }
                                x11 = x11 - dx[tmpi];
                                y11 = y11 - dy[tmpi];
                            } else { break; }
                        }
                        break;
                    }
                    if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 1) {
                        x1 = x1 + dx[tmpi];
                        y1 = y1 + dy[tmpi];
                        continue;
                    }
                    if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 0) {
                        vis[x1][y1] = 1;
                        map[x1][y1] = "1";
                        usedx = x1;
                        usedy = y1;
                        steppedx = x1;
                        steppedy = y1;
                        finished = true;
                        return;
                    }
                    x1 = x1 + dx[tmpi];
                    y1 = y1 + dy[tmpi];
                } else {
                    break;
                }
            }
        }
        if (rectmp == -1) {
            int x1 = x - dx[tmpi];
            int y1 = y - dy[tmpi];
            while (true) {
                if (x1 <= CB && y1 <= CB && x1 >= 1 && y1 >= 1) {
                    if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 2) {
                        int x11 = x1 + dx[tmpi];
                        int y11 = y1 + dy[tmpi];
                        while (true) {
                            if (x11 >= 1 && y11 >= 1 && x11 <= CB && y11 <= CB) {
                                if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                                    break;
                                }
                                if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                                    x11 = x11 + dx[tmpi];
                                    y11 = y11 + dy[tmpi];
                                    continue;
                                }
                                if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                                    vis[x11][y11] = 1;
                                    map[x11][y11] = "1";
                                    usedx = x11;
                                    usedy = y11;
                                    steppedx = x11;
                                    steppedy = y11;
                                    finished = true;
                                    return;
                                }
                                x11 = x11 + dx[tmpi];
                                y11 = y11 + dy[tmpi];
                            } else {
                                break;
                            }
                        }
                        break;
                    }
                    if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 1) {
                        x1 = x1 + dx[tmpi];
                        y1 = y1 + dy[tmpi];
                        continue;
                    }
                    if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 0) {
                        vis[x1][y1] = 1;
                        map[x1][y1] = "1";
                        usedx = x1;
                        usedy = y1;
                        steppedx = x1;
                        steppedy = y1;
                        finished = true;
                        return;
                    }
                    x1 -= dx[tmpi];
                    y1 -= dy[tmpi];
                } else {
                    break;
                }
            }
        }
        if(MIN_LENGTH == 3){
            for (int i = 1; i <= CB; i++) {
                for (int j = 1; j <= CB; j++) {
                    if (couldVis[i][j]) {
                        if (vis[i][j] == 2) {
                            continue;
                        }
                        if (vis[i][j] == 1) {
                            continue;
                        }
                        map[i][j] = "1";
                        vis[i][j] = 1;
                        usedx = i;
                        usedy = j;
                        steppedx = i;
                        steppedy = j;
                        finished = true;
                        return;
                    }
                }
            }
        }
        if(MIN_LENGTH == 2){
            checkVIS(MIN_LENGTH,2);
            for (int i = 1; i <= CB; i++) {
                for (int j = 1; j <= CB; j++) {
                    if (couldVis1[i][j]) {
                        if (vis[i][j] == 2) {
                            continue;
                        }
                        if (vis[i][j] == 1) {
                            continue;
                        }
                        map[i][j] = "1";
                        vis[i][j] = 1;
                        usedx = i;
                        usedy = j;
                        steppedx = i;
                        steppedy = j;
                        finished = true;
                        return;
                    }
                }
            }
        }
        int m = -1;
        for (int i = 0; i < 8; i++) {
            int checkwaytmp = checkAI(x, y, i);
            if (checkwaytmp >= MIN_LENGTH) {
                if (checkwaytmp == 300) {
                    continue;
                }
                if (checkwaytmp == 200) {
                    continue;
                }
                if (checkwaytmp > m) {
                    m = checkwaytmp;
                    tmpii = i;
                }
            }
        }
        if (m >= MIN_LENGTH) {
            if (rectmp1 == 1) {
                int xx = x + dx[tmpii];
                int yy = y + dy[tmpii];
                while (true) {
                    if (xx > 0 && yy > 0 && xx <= CB && yy <= CB) {
                        if (xx > 0 && yy > 0 && xx <= CB && yy <= CB && vis[xx][yy] == 0) {
                            vis[xx][yy] = 1;
                            map[xx][yy] = "1";
                            usedx = xx;
                            usedy = yy;
                            steppedx = xx;
                            steppedy = yy;
                            finished = true;
                            return;
                        }
                        if (xx > 0 && yy > 0 && xx <= CB && yy <= CB && vis[xx][yy] == 2) {
                            int x11 = xx - dx[tmpii];
                            int y11 = yy - dy[tmpii];
                            while (true) {
                                if (x11 >= 1 && y11 >= 1 && x11 <= CB && y11 <= CB) {
                                    if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                                        break;
                                    }
                                    if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                                        x11 = x11 - dx[tmpii];
                                        y11 = y11 - dy[tmpii];
                                        continue;
                                    }
                                    if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                                        vis[x11][y11] = 1;
                                        map[x11][y11] = "1";
                                        usedx = x11;
                                        usedy = y11;
                                        steppedx = x11;
                                        steppedy = y11;
                                        finished = true;
                                        return;
                                    }
                                    x11 = x11 - dx[tmpii];
                                    y11 = y11 - dy[tmpii];
                                } else {
                                    break;
                                }
                            }
                            break;
                        }
                        xx = xx + dx[tmpii];
                        yy = yy + dy[tmpii];
                    } else {
                        break;
                    }
                }
            }
            if (rectmp1 == -1) {
                int xx1 = x - dx[tmpii];
                int yy1 = y - dy[tmpii];
                while (true) {
                    if (xx1 >= 1 && yy1 >= 1 && xx1 <= CB && yy1 <= CB) {
                        if (xx1 > 0 && yy1 > 0 && xx1 <= CB && yy1 <= CB && vis[xx1][yy1] == 0) {
                            vis[xx1][yy1] = 1;
                            map[xx1][yy1] = "1";
                            usedx = xx1;
                            usedy = yy1;
                            steppedx = xx1;
                            steppedy = yy1;
                            finished = true;
                            return;
                        }
                        if (xx1 > 0 && yy1 > 0 && xx1 <= CB && yy1 <= CB && vis[xx1][yy1] == 2) {
                            int x11 = xx1 + dx[tmpii];
                            int y11 = yy1 + dy[tmpii];
                            while (true) {
                                if (x11 >= 1 && y11 >= 1 && x11 <= CB && y11 <= CB) {
                                    if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                                        break;
                                    }
                                    if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                                        x11 = x11 + dx[tmpii];
                                        y11 = y11 + dy[tmpii];
                                        continue;
                                    }
                                    if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                                        vis[x11][y11] = 1;
                                        map[x11][y11] = "1";
                                        usedx = x11;
                                        usedy = y11;
                                        steppedx = x11;
                                        steppedy = y11;
                                        finished = true;
                                        return;
                                    }
                                    x11 = x11 + dx[tmpii];
                                    y11 = y11 + dy[tmpii];
                                } else {
                                    break;
                                }
                            }
                            break;
                        }
                        xx1 = xx1 - dx[tmpii];
                        yy1 = yy1 - dy[tmpii];
                    } else {
                        break;
                    }
                }
            }
        }
    }
    if(checktmp < 1){
        if(MIN_LENGTH == 3){
            checkVIS(3,1);
            for (int i = 1; i <= CB; i++) {
                for (int j = 1; j <= CB; j++) {
                    if (couldVis[i][j]) {
                        if (vis[i][j] == 2) {
                            continue;
                        }
                        if (vis[i][j] == 1) {
                            continue;
                        }
                        map[i][j] = "1";
                        vis[i][j] = 1;
                        usedx = i;
                        usedy = j;
                        steppedx = i;
                        steppedy = j;
                        finished = true;
                        return;
                    }
                }
            }
        }
        if(MIN_LENGTH == 2){
            checkVIS(2,2);
            for (int i = 1; i <= CB; i++) {
                for (int j = 1; j <= CB; j++) {
                    if (couldVis1[i][j]) {
                        if (vis[i][j] == 2) {
                            continue;
                        }
                        if (vis[i][j] == 1) {
                            continue;
                        }
                        map[i][j] = "1";
                        vis[i][j] = 1;
                        usedx = i;
                        usedy = j;
                        steppedx = i;
                        steppedy = j;
                        finished = true;
                        return;
                    }
                }
            }
        }
    }
}
/* Defend Functions */
int checkP(int x, int y, int way) {
    int m = -1;
    int tmpans = 0;
    int x1, y1, x11, y11;
    x1 = x11 = x;
    y1 = y11 = y;
    for (int i = 1; i < 6; i++) {
        if (x1 >= 1 && y1 >= 1 && x1 <= CB && y1 <= CB) {
            x1 += dx[way];
            y1 += dy[way];
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 0) {
                break;
            }
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 2) {
                tmpans++;
            }
            if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 1) {
                if(tmpans == 0)
                    return 300;
            } else {
                if (tmpans == 0) {
                    break;
                }
            }
        }
    }
    if (tmpans > m && tmpans > 0) {
        m = tmpans;
        rectmp2 = 1;
    }
    tmpans = 0;
    for (int i = 1; i < 6; i++) {
        if (x11 >= 1 && y11 >= 1 && x11 <= CB && y11 <= CB) {
            x11 -= dx[way];
            y11 -= dy[way];
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                break;
            }
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                tmpans++;
            }
            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                if(tmpans == 0)
                    return 300;
            } else {
                if (tmpans == 0) {
                    tmpans = 0;
                    break;
                }
            }
        }
    }
    if (tmpans > m && tmpans > 0) {
        m = tmpans;
        rectmp2 = -1;
    }

    return m;
}
void defend(int x, int y, int MIN_LENGTH){
    int defendtmp;
    int dway = 0;
    int m = -1;
    int cnt = 0;
    int cnt1 = 0;
    for(int i = 0; i<8; i++){
        defendtmp = checkP(x,y,i);
        if(defendtmp >= MIN_LENGTH){
            if(defendtmp == 300){
                continue;
            }
            if(defendtmp > m){
                if(defendtmp >= MIN_LENGTH){
                    m = defendtmp;
                    dway = i;
                }
            }
        }else if(defendtmp == 1){
            m = defendtmp;
            dway = i;
        }
    }
    if(m == 4){
        cout << "PLAYER HAS WON!" << endl;
        system("pause");
        exit(0);
    }
    if (rectmp2 == 1) {
        int xx = x + dx[dway];
        int yy = y + dy[dway];
        cnt++;
        while (true) {
            if (xx > 0 && yy > 0 && xx <= CB && yy <= CB) {
                if (xx > 0 && yy > 0 && xx <= CB && yy <= CB && vis[xx][yy] == 0) {
                    if(cnt >= MIN_LENGTH){
                        vis[xx][yy] = 1;
                        map[xx][yy] = "1";
                        usedx = xx;
                        usedy = yy;
                        steppedx = xx;
                        steppedy = yy;
                        finished = true;
                        return;
                    }else{
                        if(cnt == 3){
                            DECouldvis[xx][yy] = true;
                        }
                        if(cnt == 2){
                            DECouldvis1[xx][yy] = true;
                        }
                        break;
                    }
                }
                if (xx > 0 && yy > 0 && xx <= CB && yy <= CB && vis[xx][yy] == 1) {
                    int x11 = xx - dx[dway];
                    int y11 = yy - dy[dway];
                    cnt1++;
                    while (true) {
                        if (x11 >= 1 && y11 >= 1 && x11 <= CB && y11 <= CB) {
                            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                                break;
                            }
                            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                                cnt1++;
                                x11 = x11 - dx[dway];
                                y11 = y11 - dy[dway];
                                continue;
                            }
                            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                                if(cnt1 >= MIN_LENGTH){
                                    vis[x11][y11] = 1;
                                    map[x11][y11] = "1";
                                    usedx = x11;
                                    usedy = y11;
                                    steppedx = x11;
                                    steppedy = y11;
                                    finished = true;
                                    return;
                                }else{
                                    if(cnt1 == 3){
                                        DECouldvis[x11][y11] = true;
                                    }
                                    if(cnt1 == 2){
                                        DECouldvis1[x11][y11] = true;
                                    }
                                    break;
                                }
                            }
                        } else {
                            break;
                        }
                    }
                    break;
                }
                xx = xx + dx[dway];
                yy = yy + dy[dway];
                if(vis[xx][yy] == 2) {
                    cnt++;
                }
            } else {
                break;
            }
        }
    }
    cnt = 0;
    cnt1 = 0;
    if (rectmp2 == -1) {
        cnt++;
        int xx1 = x - dx[dway];
        int yy1 = y - dy[dway];
        while (true) {
            if (xx1 >= 1 && yy1 >= 1 && xx1 <= CB && yy1 <= CB) {
                if (xx1 > 0 && yy1 > 0 && xx1 <= CB && yy1 <= CB && vis[xx1][yy1] == 0) {
                    if(cnt >= MIN_LENGTH){
                        vis[xx1][yy1] = 1;
                        map[xx1][yy1] = "1";
                        usedx = xx1;
                        usedy = yy1;
                        steppedx = xx1;
                        steppedy = yy1;
                        finished = true;
                        return;
                    }else{
                        if(cnt == 3){
                            DECouldvis[xx1][yy1] = true;
                        }
                        if(cnt == 2){
                            DECouldvis1[xx1][yy1] = true;
                        }
                        break;
                    }
                }
                if (xx1 > 0 && yy1 > 0 && xx1 <= CB && yy1 <= CB && vis[xx1][yy1] == 1) {
                    int x11 = xx1 + dx[dway];
                    int y11 = yy1 + dy[dway];
                    cnt1++;
                    while (true) {
                        if (x11 >= 1 && y11 >= 1 && x11 <= CB && y11 <= CB) {
                            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 1) {
                                break;
                            }
                            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 2) {
                                cnt1++;
                                x11 = x11 + dx[dway];
                                y11 = y11 + dy[dway];
                                continue;
                            }
                            if (x11 > 0 && y11 > 0 && x11 <= CB && y11 <= CB && vis[x11][y11] == 0) {
                                if(cnt1 >= MIN_LENGTH){
                                    vis[x11][y11] = 1;
                                    map[x11][y11] = "1";
                                    usedx = x11;
                                    usedy = y11;
                                    steppedx = x11;
                                    steppedy = y11;
                                    finished = true;
                                    return;
                                }else{
                                    if(cnt1 == 3){
                                        DECouldvis[x11][y11] = true;
                                    }
                                    if(cnt1 == 2){
                                        DECouldvis1[x11][y11] = true;
                                    }
                                    break;
                                }
                            }
                        } else {
                            break;
                        }
                    }
                    break;
                }
                xx1 = xx1 - dx[dway];
                yy1 = yy1 - dy[dway];
                if(vis[xx1][yy1] == 2){
                    cnt++;
                }
            } else {
                break;
            }
        }
    }
    for(int i = 0; i<8; i++){
        bool flag = false;
        if(vis[x+dx[i]][y+dy[i]] == 2&&x+dx[i]>= 1 && x+dx[i] <= CB && y+ dy[i] >= 1 && y+dy[i] <=CB){
            int cnt21 = 0;
            int xx = x;
            int yy = y;
            for(int i1 = 0; i1 <= 6; i1++){
                xx+= dx[i];
                yy += dy[i];
                if(xx >= 1 && yy >= 1 && xx <= CB && yy <= CB){
                    if(vis[xx][yy] == 2){
                        continue;
                    }
                    if(vis[xx][yy] != 2){
                        int xxx = xx;
                        int yyy = yy;
                        for(int i2 = 0; i2<=6; i2++){
                            xxx -= dx[i];
                            yyy -= dy[i];
                            if(xxx >= 1 && yyy >= 1 && xxx <= CB && yyy <= CB){
                                if(vis[xxx][yyy] == 2){
                                    if(vis[xxx-dx[i]][yyy-dy[i]] == 2) {
                                        cnt21++;
                                    }
                                    continue;
                                }
                                if(vis[xxx][yyy] == 0){
                                    if(cnt21 >= MIN_LENGTH){
                                        vis[xxx][yyy] = 1;
                                        map[xxx][yyy] = "1";
                                        usedx = xxx;
                                        usedy = yyy;
                                        steppedx = xxx;
                                        steppedy = yyy;
                                        finished = true;
                                        return;
                                    }else{
                                        if(cnt21 == 3){
                                            DECouldvis[xxx][yyy] = true;
                                        }
                                        if(cnt21 == 2){
                                            DECouldvis1[xxx][yyy] = true;
                                        }
                                        flag = true;
                                        cnt21 = 0;
                                        break;
                                    }
                                }
                                if(vis[xxx][yyy] == 1){
                                    flag = true;
                                    cnt21 = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(flag){
                    break;
                }
            }
        }
    }

}
/* Main */
void run(int x, int y){
    defend(px,py,3);
    if(finished){
        finished = false;
        return;
    }
    for(int i = 1; i<=CB; i++){
        for(int j = 1; j<=CB; j++){
            if(DECouldvis[i][j]){
                if(vis[i][j] == 1){
                    continue;
                }
                if(vis[i][j] == 2){
                    continue;
                }
                map[i][j] = "1";
                vis[i][j] = 1;
                usedx = i;
                usedy = j;
                steppedx = i;
                steppedy = j;
                finished = false;
                return;
            }
        }
    }
    attack(x,y,3);
    if(finished){
        finished = false;
        return;
    }
    defend(px,py,2);
    if(finished){
        finished = false;
        return;
    }
    for(int i = 1; i<=CB; i++){
        for(int j = 1; j<=CB; j++){
            if(DECouldvis1[i][j]){
                if(vis[i][j] == 1){
                    continue;
                }
                if(vis[i][j] == 2){
                    continue;
                }
                map[i][j] = "1";
                vis[i][j] = 1;
                usedx = i;
                usedy = j;
                steppedx = i;
                steppedy = j;
                finished = false;
                return;
            }
        }
    }
    attack(x,y,2);
    if(finished){
        finished = false;
        return;
    }
    checkVIS(1,3);
    for (int i = 1; i <= CB; i++) {
        for (int j = 1; j <= CB; j++) {
            if (couldVis2[i][j]) {
                if (vis[i][j] == 2) {
                    continue;
                }
                if (vis[i][j] == 1) {
                    continue;
                }
                map[i][j] = "1";
                vis[i][j] = 1;
                usedx = i;
                usedy = j;
                steppedx = i;
                steppedy = j;
                finished = false;
                return;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx > 0 && yy > 0 && xx <= CB && yy <= CB && vis[xx][yy] == 0) {
            vis[xx][yy] = 1;
            map[xx][yy] = "1";
            usedx = xx;
            usedy = yy;
            steppedx = xx;
            steppedy = yy;
            finished = false;
            return;
        }
    }
}
int main() {
    //h121ND
    cout << "This is Beta V.2.3.4" << endl;
    reset();
    cout << "Please select your mode: " << endl;
    cout << "1. Human VS. AI" << endl;
    cout << "2. FREESTYLE (BETA)" << endl;
    cout << "Enter your mode: ";
    cin >> MAINMODE;
    if(MAINMODE == 1){
        bool k;
        map[CEN][CEN] = "1";
        vis[CEN][CEN] = 1;
        steppedx = CEN;
        steppedy = CEN;
        print();
        int tmpx1, tmpy1;
        k = true;
        while (steps <= 500000) {
            if (steps == 1) {
                while (true) {
                    int number = random();
                    int x1 = CEN + dx[number];
                    int y1 = CEN + dy[number];
                    if (x1 > 0 && y1 > 0 && x1 <= CB && y1 <= CB && vis[x1][y1] == 0) {
                        vis[x1][y1] = 1;
                        map[x1][y1] = "1";
                        tmpx1 = x1;
                        tmpy1 = y1;
                        steppedx = x1;
                        steppedy = y1;
                        break;
                    } else {
                        continue;
                    }
                }
                steps++;
                k = true;
                print();
            }
            if (!k) {
                run(tmpx1, tmpy1);
                print();
                tmpx1 = usedx;
                tmpy1 = usedy;
            }
            bool ok = false;
            string tmpxxx, tmpyyy;
            cout << "Enter where you want to place the piece (Enter 'help 1' to enter the help utility): " << endl;
            cin >> tmpxxx >> tmpyyy;
            while (!ok) {
                if(tmpxxx == "help" && tmpyyy == "1"){
                    help();
                    cout << "Enter where you want to place the piece: " << endl;
                    cin >> tmpxxx >> tmpyyy;
                    try {
                        if(stoi(tmpxxx) > CB || stoi(tmpxxx) < 1||
                           stoi(tmpyyy) > CB || stoi(tmpyyy) < 1){
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                        if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 1) {
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                        if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 2) {
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                    } catch (invalid_argument &ab) {
                        cout << "ERROR!" << "ENTER AGAIN: ";
                        cin >> tmpxxx >> tmpyyy;
                        continue;
                    } catch (out_of_range &bc) {
                        cout << "ERROR!" << "ENTER AGAIN: ";
                        cin >> tmpxxx >> tmpyyy;
                        continue;
                    }
                    ok = true;
                }else{
                    try {
                        if(stoi(tmpxxx) > CB || stoi(tmpxxx) < 1||
                           stoi(tmpyyy) > CB || stoi(tmpyyy) < 1){
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                        if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 1) {
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                        if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 2) {
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                    } catch (invalid_argument &ab) {
                        cout << "ERROR!" << "ENTER AGAIN: ";
                        cin >> tmpxxx >> tmpyyy;
                        continue;
                    } catch (out_of_range &bc) {
                        cout << "ERROR!" << "ENTER AGAIN: ";
                        cin >> tmpxxx >> tmpyyy;
                        continue;
                    }
                    ok = true;
                }
            }
            px = stoi(tmpxxx);
            py = stoi(tmpyyy);
            system("cls");
            map[stoi(tmpxxx)][stoi(tmpyyy)] = "2";
            vis[stoi(tmpxxx)][stoi(tmpyyy)] = 2;
            print();
            k = false;
            steps++;
        }
    }
    if(MAINMODE == 2){
        bool Fin = false;
        while (steps <= 500000) {
            if(steps%2==0){
                bool k = true;
                int tmpx1, tmpy1;
                bool ok = false;
                string tmpxxx, tmpyyy;
                print();
                cout << "Enter where you want to place the piece (Enter 'ret 1' to retreat): " << endl;
                cin >> tmpxxx >> tmpyyy;
                while (!ok) {
                    if(tmpxxx == "ret" && tmpyyy == "1"){
                        retreat(2);
                        cout << "Enter where you want to place the piece: " << endl;
                        cin >> tmpxxx >> tmpyyy;
                        while(true){
                            try {
                                if(stoi(tmpxxx) > CB || stoi(tmpxxx) < 1||
                                   stoi(tmpyyy) > CB || stoi(tmpyyy) < 1){
                                    cout << "ERROR!" << "ENTER AGAIN: ";
                                    cin >> tmpxxx >> tmpyyy;
                                    continue;
                                }
                                if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 1) {
                                    cout << "ERROR!" << "ENTER AGAIN: ";
                                    cin >> tmpxxx >> tmpyyy;
                                    continue;
                                }
                                if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 2) {
                                    cout << "ERROR!" << "ENTER AGAIN: ";
                                    cin >> tmpxxx >> tmpyyy;
                                    continue;
                                }
                            } catch (invalid_argument &ab) {
                                cout << "ERROR!" << "ENTER AGAIN: ";
                                cin >> tmpxxx >> tmpyyy;
                                continue;
                            } catch (out_of_range &bc) {
                                cout << "ERROR!" << "ENTER AGAIN: ";
                                cin >> tmpxxx >> tmpyyy;
                                continue;
                            }
                            break;
                        }
                        REMX = stoi(tmpxxx);
                        REMY = stoi(tmpyyy);
                        vis[stoi(tmpxxx)][stoi(tmpyyy)] = 2;
                        map[stoi(tmpxxx)][stoi(tmpyyy)] = "2";
                        Fin = true;
                        steps++;
                        break;
                    }

                    try {
                        if(stoi(tmpxxx) > CB || stoi(tmpxxx) < 1||
                           stoi(tmpyyy) > CB || stoi(tmpyyy) < 1){
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                        if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 1) {
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                        if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 2) {
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                    } catch (invalid_argument &ab) {
                        cout << "ERROR!" << "ENTER AGAIN: ";
                        cin >> tmpxxx >> tmpyyy;
                        continue;
                    } catch (out_of_range &bc) {
                        cout << "ERROR!" << "ENTER AGAIN: ";
                        cin >> tmpxxx >> tmpyyy;
                        continue;
                    }
                    ok = true;
                }
                system("cls");
                if(!Fin){
                    REMX = stoi(tmpxxx);
                    REMY = stoi(tmpyyy);
                    map[stoi(tmpxxx)][stoi(tmpyyy)] = "1";
                    vis[stoi(tmpxxx)][stoi(tmpyyy)] = 1;
                }
                Fin = false;
                print();
                k = false;
                steps++;
            }else{
                bool k = true;
                int tmpx1, tmpy1;
                bool ok = false;
                string tmpxxx, tmpyyy;
                print();
                cout << "Enter where you want to place the piece (Enter 'ret 1' to retreat): " << endl;
                cin >> tmpxxx >> tmpyyy;
                while (!ok) {
                    if(tmpxxx == "ret" && tmpyyy == "1"){
                        retreat(2);
                        cout << "Enter where you want to place the piece: " << endl;
                        cin >> tmpxxx >> tmpyyy;
                        while(true){
                            try {
                                if(stoi(tmpxxx) > CB || stoi(tmpxxx) < 1||
                                   stoi(tmpyyy) > CB || stoi(tmpyyy) < 1){
                                    cout << "ERROR!" << "ENTER AGAIN: ";
                                    cin >> tmpxxx >> tmpyyy;
                                    continue;
                                }
                                if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 1) {
                                    cout << "ERROR!" << "ENTER AGAIN: ";
                                    cin >> tmpxxx >> tmpyyy;
                                    continue;
                                }
                                if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 2) {
                                    cout << "ERROR!" << "ENTER AGAIN: ";
                                    cin >> tmpxxx >> tmpyyy;
                                    continue;
                                }
                            } catch (invalid_argument &ab) {
                                cout << "ERROR!" << "ENTER AGAIN: ";
                                cin >> tmpxxx >> tmpyyy;
                                continue;
                            } catch (out_of_range &bc) {
                                cout << "ERROR!" << "ENTER AGAIN: ";
                                cin >> tmpxxx >> tmpyyy;
                                continue;
                            }
                            break;
                        }
                        REMX = stoi(tmpxxx);
                        REMY = stoi(tmpyyy);
                        vis[stoi(tmpxxx)][stoi(tmpyyy)] = 1;
                        map[stoi(tmpxxx)][stoi(tmpyyy)] = "1";
                        steps++;
                        Fin = true;
                        break;
                    }
                    try {
                        if(stoi(tmpxxx) > CB || stoi(tmpxxx) < 1||
                           stoi(tmpyyy) > CB || stoi(tmpyyy) < 1){
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                        if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 1) {
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                        if (vis[stoi(tmpxxx)][stoi(tmpyyy)] == 2) {
                            cout << "ERROR!" << "ENTER AGAIN: ";
                            cin >> tmpxxx >> tmpyyy;
                            continue;
                        }
                    } catch (invalid_argument &ab) {
                        cout << "ERROR!" << "ENTER AGAIN: ";
                        cin >> tmpxxx >> tmpyyy;
                        continue;
                    } catch (out_of_range &bc) {
                        cout << "ERROR!" << "ENTER AGAIN: ";
                        cin >> tmpxxx >> tmpyyy;
                        continue;
                    }
                    ok = true;
                }
                system("cls");
                if(!Fin){
                    REMX = stoi(tmpxxx);
                    REMY = stoi(tmpyyy);
                    map[stoi(tmpxxx)][stoi(tmpyyy)] = "2";
                    vis[stoi(tmpxxx)][stoi(tmpyyy)] = 2;
                }
                Fin = false;
                print();
                k = false;
                steps++;
            }
        }
    }
    return 0;
}