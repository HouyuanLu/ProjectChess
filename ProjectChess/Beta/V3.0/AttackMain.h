/* Attack Functions */
#include "Functions.h"
#include "AttackFunc.h"
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