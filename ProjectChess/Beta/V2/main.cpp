#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int usedx, usedy;
int px,py;
int vis[21][21];
int tmpi = 0;
int tmpii = 0;
int rectmp = 0;
int rectmp1 = 0;
int rectmp2 = 0;
string map[21][21];
int stepsq = 0;
int steps = 0;
bool couldVis[21][21];
bool couldVis1[21][21];
bool couldVis2[21][21];
bool finished = false;
int steppedx = 0; int steppedy = 0;
int dx[] = {-1,-1,0,1,1,1,-1,-1};
int dy[] = {0,1,1,1,0,-1,0,-1};
//h126N

//todo: ERROR: CheckVis3 not working properly: CheckVIS/Mode3
//todo: ERROR: Going to far from where it should be: defend
//todo: SUGGEST: ADD MIN_LENGTH to attack: attack
//todo: SUGGEST: DEFENSE: Add to start from the first one in the row not the middle: CheckP or defend(mode 3)
//todo: SUGGEST: HARD: ADD DEFENSE(beta) (working...)
void print(){
    bool kk = false;
    for(int i = 0; i<=20; i++){
        for(int j = 0; j<=20; j++){
            if(i == 0&&map[i][j]>="10" && map[i][j] <= "20"){
                cout << map[i][j] << " ";
                kk = true;
            }
            if(j == 0&&map[i][j] >="10" && map[i][j]<="20"){
                cout << map[i][j] << " ";
                kk = true;
            }
            if(steppedx == i&&steppedy == j){
                if(steppedx == 10 && steppedy == 10){
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
        steppedx = 10;
        steppedy = 10;
        stepsq++;
    }
    cout << "Computer has chosen:" << " "<< steppedx <<" "<< "and"<<" "<< steppedy << endl;
    stepsq++;
}
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
        if (x1 >= 1 && y1 >= 1 && x1 <= 20 && y1 <= 20) {
            x1 += dx[way];
            y1 += dy[way];
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 0) {
                if (tmpans >= 3) {
                    couldVis[x1][y1] = true;
                    int xxx = x1, yyy = y1;
                    for (int j = 1; j < 6; j++) {
                        if (xxx >= 1 && yyy >= 1 && xxx <= 20 && yyy <= 20) {
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
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 2) {
                return 300;
            }
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 1) {
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
        if (x11 >= 1 && y11 >= 1 && x11 <= 20 && y11 <= 20) {
            x11 -= dx[way];
            y11 -= dy[way];
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
                if (tmpans >= 3) {
                    couldVis[x11][y11] = true;
                    int xxx = x11, yyy = y11;
                    for (int j = 1; j < 6; j++) {
                        if (xxx >= 1 && yyy >= 1 && xxx <= 20 && yyy <= 20) {
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
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                return 300;
            }
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
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
        if (xx1 > 0 && yy1 > 0 && xx1 <= 20 && yy1 <= 20 && vis[xx1][yy1] == 1) {
            tmpi = i;
            break;
        }
    }
    for (int i = 1; i < 6; i++) {
        if (x1 >= 1 && y1 >= 1 && x1 <= 20 && y1 <= 20) {
            x1 += dx[tmpi];
            y1 += dy[tmpi];
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 0) {
                if (tmpans >= 3) {
                    couldVis[x1][y1] = true;
                    int xxx = x1, yyy = y1;
                    for (int j = 1; j < 6; j++) {
                        if (xxx >= 1 && yyy >= 1 && xxx <= 20 && yyy <= 20) {
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
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 2) {
                break;
            }
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 1) {
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
        if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
            x11 -= dx[tmpi];
            y11 -= dy[tmpi];
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
                if (tmpans >= 3) {
                    couldVis[x11][y11] = true;
                    int xxx = x11, yyy = y11;
                    for (int j = 1; j < 6; j++) {
                        if (xxx >= 1 && yyy >= 1 && xxx <= 20 && yyy <= 20) {
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
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                break;
            }
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
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
        int cnt = 0;
        int cnt1 = 0;
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
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
                                    if (xx >= 1 && yy >= 1 && xx <= 20 && yy <= 20) {
                                        xx += dx[visway];
                                        yy += dy[visway];
                                        if (xx <= 20 && yy <= 20 && xx >= 1 && yy >= 1) {
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
                                    if (xx <= 20 && yy <= 20 && xx >= 1 && yy >= 1) {
                                        xx -= dx[visway];
                                        yy -= dy[visway];
                                        if (xx <= 20 && yy <= 20 && xx >= 1 && yy >= 1) {
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
        int cnt = 0;
        int cnt1 = 0;
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
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
                                    if (xx >= 1 && yy >= 1 && xx <= 20 && yy <= 20) {
                                        xx += dx[visway];
                                        yy += dy[visway];
                                        if (xx <= 20 && yy <= 20 && xx >= 1 && yy >= 1) {
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
                                    if (xx <= 20 && yy <= 20 && xx >= 1 && yy >= 1) {
                                        xx -= dx[visway];
                                        yy -= dy[visway];
                                        if (xx >= 1 && yy >= 1 && xx <= 20 && yy <= 20) {
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
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
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
                                    if (xx >= 1 && yy >= 1 && xx <= 20 && yy <= 20) {
                                        xx += dx[visway];
                                        yy += dy[visway];
                                        if (xx <= 20 && yy <= 20 && xx >= 1 && yy >= 1) {
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
                                    if (xx <= 20 && yy <= 20 && xx >= 1 && yy >= 1) {
                                        xx -= dx[visway];
                                        yy -= dy[visway];
                                        if (xx >= 1 && yy >= 1 && xx <= 20 && yy <= 20) {
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
void attack(int x, int y) {
    checkVIS(3, 1);
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
                if (x1 >= 1 && y1 >= 1 && x1 <= 20 && y1 <= 20) {
                    if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 2) {
                        int x11 = x1 - dx[tmpi];
                        int y11 = y1 - dy[tmpi];
                        while (true) {
                            if (x11 >= 1 && y11 >= 1 && x11 <= 20 && y11 <= 20) {
                                if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                                    break;
                                }
                                if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
                                    x11 = x11 - dx[tmpi];
                                    y11 = y11 - dy[tmpi];
                                    continue;
                                }
                                if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
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
                    if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 1) {
                        x1 = x1 + dx[tmpi];
                        y1 = y1 + dy[tmpi];
                        continue;
                    }
                    if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 0) {
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
                if (x1 <= 20 && y1 <= 20 && x1 >= 1 && y1 >= 1) {
                    if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 2) {
                        int x11 = x1 + dx[tmpi];
                        int y11 = y1 + dy[tmpi];
                        while (true) {
                            if (x11 >= 1 && y11 >= 1 && x11 <= 20 && y11 <= 20) {
                                if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                                    break;
                                }
                                if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
                                    x11 = x11 + dx[tmpi];
                                    y11 = y11 + dy[tmpi];
                                    continue;
                                }
                                if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
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
                    if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 1) {
                        x1 = x1 + dx[tmpi];
                        y1 = y1 + dy[tmpi];
                        continue;
                    }
                    if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 0) {
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
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
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
        checkVIS(2,2);
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
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
        int m = -1;
        for (int i = 0; i < 8; i++) {
            int checkwaytmp = checkAI(x, y, i);
            if (checkwaytmp >= 2) {
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
        if (m >= 2) {
            if (rectmp1 == 1) {
                int xx = x + dx[tmpii];
                int yy = y + dy[tmpii];
                while (true) {
                    if (xx > 0 && yy > 0 && xx <= 20 && yy <= 20) {
                        if (xx > 0 && yy > 0 && xx <= 20 && yy <= 20 && vis[xx][yy] == 0) {
                            vis[xx][yy] = 1;
                            map[xx][yy] = "1";
                            usedx = xx;
                            usedy = yy;
                            steppedx = xx;
                            steppedy = yy;
                            finished = true;
                            return;
                        }
                        if (xx > 0 && yy > 0 && xx <= 20 && yy <= 20 && vis[xx][yy] == 2) {
                            int x11 = xx - dx[tmpii];
                            int y11 = yy - dy[tmpii];
                            while (true) {
                                if (x11 >= 1 && y11 >= 1 && x11 <= 20 && y11 <= 20) {
                                    if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                                        break;
                                    }
                                    if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
                                        x11 = x11 - dx[tmpii];
                                        y11 = y11 - dy[tmpii];
                                        continue;
                                    }
                                    if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
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
                    if (xx1 >= 1 && yy1 >= 1 && xx1 <= 20 && yy1 <= 20) {
                        if (xx1 > 0 && yy1 > 0 && xx1 <= 20 && yy1 <= 20 && vis[xx1][yy1] == 0) {
                            vis[xx1][yy1] = 1;
                            map[xx1][yy1] = "1";
                            usedx = xx1;
                            usedy = yy1;
                            steppedx = xx1;
                            steppedy = yy1;
                            finished = true;
                            return;
                        }
                        if (xx1 > 0 && yy1 > 0 && xx1 <= 20 && yy1 <= 20 && vis[xx1][yy1] == 2) {
                            int x11 = xx1 + dx[tmpii];
                            int y11 = yy1 + dy[tmpii];
                            while (true) {
                                if (x11 >= 1 && y11 >= 1 && x11 <= 20 && y11 <= 20) {
                                    if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                                        break;
                                    }
                                    if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
                                        x11 = x11 + dx[tmpii];
                                        y11 = y11 + dy[tmpii];
                                        continue;
                                    }
                                    if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
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
        checkVIS(3,1);
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
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
        checkVIS(2,2);
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
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
int checkP(int x, int y, int way) {
    int m = -1;
    int tmpans = 0;
    int x1, y1, x11, y11;
    x1 = x11 = x;
    y1 = y11 = y;
    for (int i = 1; i < 6; i++) {
        if (x1 >= 1 && y1 >= 1 && x1 <= 20 && y1 <= 20) {
            x1 += dx[way];
            y1 += dy[way];
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 0) {
                break;
            }
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 2) {
                tmpans++;
            }
            if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 1) {
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
        if (x11 >= 1 && y11 >= 1 && x11 <= 20 && y11 <= 20) {
            x11 -= dx[way];
            y11 -= dy[way];
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
                break;
            }
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                tmpans++;
            }
            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
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
                if(m >= MIN_LENGTH){
                    m = defendtmp;
                    dway = i;
                }
            }
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
            if (xx > 0 && yy > 0 && xx <= 20 && yy <= 20) {
                if (xx > 0 && yy > 0 && xx <= 20 && yy <= 20 && vis[xx][yy] == 0) {
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
                        cnt = 0;
                        break;
                    }
                }
                if (xx > 0 && yy > 0 && xx <= 20 && yy <= 20 && vis[xx][yy] == 1) {
                    int x11 = xx;
                    int y11 = yy;
                    cnt1++;
                    while (true) {
                        if (x11 >= 1 && y11 >= 1 && x11 <= 20 && y11 <= 20) {
                            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
                                break;
                            }
                            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                                cnt1++;
                                x11 = x11 - dx[dway];
                                y11 = y11 - dy[dway];
                                continue;
                            }
                            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
                                if(cnt1 >= MIN_LENGTH){
                                    vis[x11][y11] = 1;
                                    map[x11][y11] = "1";
                                    usedx = x11;
                                    usedy = y11;
                                    steppedx = x11;
                                    steppedy = y11;
                                    finished = true;
                                    return;
                                }
                            }
                            cnt1++;
                            x11 = x11 - dx[dway];
                            y11 = y11 - dy[dway];
                        } else {
                            break;
                        }
                    }
                    break;
                }
                xx = xx + dx[dway];
                yy = yy + dy[dway];
                cnt++;
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
            if (xx1 >= 1 && yy1 >= 1 && xx1 <= 20 && yy1 <= 20) {
                if (xx1 > 0 && yy1 > 0 && xx1 <= 20 && yy1 <= 20 && vis[xx1][yy1] == 0) {
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
                        cnt = 0;
                        break;
                    }
                }
                if (xx1 > 0 && yy1 > 0 && xx1 <= 20 && yy1 <= 20 && vis[xx1][yy1] == 1) {
                    int x11 = xx1;
                    int y11 = yy1;
                    cnt1++;
                    while (true) {
                        if (x11 >= 1 && y11 >= 1 && x11 <= 20 && y11 <= 20) {
                            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 1) {
                                break;
                            }
                            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2) {
                                cnt1++;
                                x11 = x11 + dx[dway];
                                y11 = y11 + dy[dway];
                                continue;
                            }
                            if (x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0) {
                                if(cnt1 >= MIN_LENGTH){
                                    vis[x11][y11] = 1;
                                    map[x11][y11] = "1";
                                    usedx = x11;
                                    usedy = y11;
                                    steppedx = x11;
                                    steppedy = y11;
                                    finished = true;
                                    return;
                                }
                            }
                            cnt1++;
                            x11 = x11 + dx[dway];
                            y11 = y11 + dy[dway];
                        } else {
                            break;
                        }
                    }
                    break;
                }
                cnt++;
                xx1 = xx1 - dx[dway];
                yy1 = yy1 - dy[dway];
            } else {
                break;
            }
        }
    }
    for(int i = 0; i<8; i++){
        bool flag = false;
        if(vis[x+dx[i]][y+dy[i]] == 2&&x+dx[i]>= 1 && x+dx[i] <= 20 && y+ dy[i] >= 1 && y+dy[i] <=20){
            int cnt21 = 0;
            int xx = x;
            int yy = y;
            for(int i1 = 0; i1 <= 6; i1++){
                xx+= dx[i];
                yy += dy[i];
                if(xx >= 1 && yy >= 1 && xx <= 20 && yy <= 20){
                    if(vis[xx][yy] == 2){
                        continue;
                    }
                    if(vis[xx][yy] != 2){
                        int xxx = xx;
                        int yyy = yy;
                        for(int i2 = 0; i2<=6; i2++){
                            xxx -= dx[i];
                            yyy -= dy[i];
                            if(xxx >= 1 && yyy >= 1 && xxx <= 20 && yyy <= 20){
                                if(vis[xxx][yyy] == 2){
                                    cnt21++;
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
                                        flag = true;
                                        cnt21 = true;
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
                    flag = false;
                    cnt21 = 0;
                    break;
                }
            }
        }
    }

}
void run(int x, int y){
    defend(px,py,3);
    if(finished){
        finished = false;
        return;
    }
    attack(x,y);
    if(finished){
        finished = false;
        return;
    }
    defend(px,py,2);
    if(finished){
        finished = false;
        return;
    }
    finished = false;

    checkVIS(1,3);
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
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
                finished = true;
                return;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx > 0 && yy > 0 && xx <= 20 && yy <= 20 && vis[xx][yy] == 0) {
            vis[xx][yy] = 1;
            map[xx][yy] = "1";
            usedx = xx;
            usedy = yy;
            steppedx = xx;
            steppedy = yy;
            finished = true;
            return;
        }
    }
}
int main() {
    //h54ND
    cout << "This is Beta V.2.0" << endl;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            map[i][j] = ".";
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= 20; i++) {
        map[0][i] = to_string(cnt1);
        cnt1++;
    }
    for (int i = 0; i <= 20; i++) {
        map[i][0] = to_string(cnt2);
        cnt2++;
    }

    bool k;
    map[10][10] = "1";
    vis[10][10] = 1;
    steppedx = 10;
    steppedy = 10;
    print();
    int tmpx1, tmpy1;
    k = true;
    while (steps <= 50000) {
        if (steps == 1) {
            while (true) {
                int number;
                srand(time(nullptr));
                number = rand() % 8;
                if (number == 8) {
                    continue;
                } else {
                    int x1 = 10 + dx[number];
                    int y1 = 10 + dy[number];
                    if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 0) {
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
        string tmpxxx, tmpyyy;
        cin >> tmpxxx >> tmpyyy;
        bool ok = false;
        while (!ok) {
            try {
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
                ok = true;
            } catch (invalid_argument &ab) {
                cout << "ERROR!" << "ENTER AGAIN: ";
                cin >> tmpxxx >> tmpyyy;
                continue;
            } catch (out_of_range &bc) {
                cout << "ERROR!" << "ENTER AGAIN: ";
                cin >> tmpxxx >> tmpyyy;
                continue;
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
    return 0;
}