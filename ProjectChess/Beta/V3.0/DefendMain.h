#include "Functions.h"
#include "DefendFunc.h"
/* Defend Functions */
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