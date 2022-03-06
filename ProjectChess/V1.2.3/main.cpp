#include <iostream>
#include <ctime>
using namespace std;
int usedx, usedy;
int vis[21][21];
int tmpi = 0;
int tmpii = 0;
int rectmp = 0;
int rectmp1 = 0;
string map[21][21];
int steps = 0;
bool couldVis[21][21];
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
}
int dx[] = {-1,-1,0,1,1,1,-1,-1};
int dy[] = {0,1,1,1,0,-1,0,-1};
//hh
int checkAI(int x, int y) {
    int m = -1;
    int tmpans = 0;
    int xx = x;
    int yy = y;
    int x1,y1,x11,y11;
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
        x1 += dx[tmpi];
        y1 += dy[tmpi];
        if(x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 0){
            if(tmpans >= 2){
                couldVis[x1][y1] = true;
                break;
            }
        }
        if(x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 2){
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
    if(tmpans > m){
        m = tmpans;
        rectmp = 1;
    }
    tmpans = 0;
    for (int i = 1; i < 6; i++) {
        x11 -= dx[tmpi];
        y11 -= dy[tmpi];
        if(x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0){
            if(tmpans >= 2){
                couldVis[x11][y11] = true;
                break;
            }
        }
        if(x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2){
            break;
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
    if(tmpans > m){
        m = tmpans;
        rectmp = -1;
    }
    return m;
}
int checkAI(int x, int y, int way) {
    int m = -1;
    if(way == tmpi){
        return 200;
    }
    int tmpans = 0;
    int x1,y1,x11,y11;
    x1 = x11 = x;
    y1 = y11 = y;
    for (int i = 1; i< 6; i++) {
        x1 += dx[way];
        y1 += dy[way];
        if(x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 0){
            if(tmpans >= 2){
                couldVis[x1][y1] = true;
                break;
            }
        }
        if(x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 2){
            return 300;
        }
        if (x1 > 0 && y1 > 0 && x1 <= 20 && y1 <= 20 && vis[x1][y1] == 1) {
            tmpans++;
        }else{
            if(tmpans == 0){
                break;
            }
        }
    }
    if(tmpans > m){
        m = tmpans;
        rectmp1 = 1;
    }
    tmpans = 0;
    for (int i = 1; i < 6; i++) {
        x11 -= dx[way];
        y11 -= dy[way];
        if(x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 0){
            if(tmpans >= 2){
                couldVis[x11][y11] = true;
                break;
            }
        }
        if(x11 > 0 && y11 > 0 && x11 <= 20 && y11 <= 20 && vis[x11][y11] == 2){
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
    if(tmpans > m){
        m = tmpans;
        rectmp1 = -1;
    }
    return m;
}
void run(int x, int y){
    int checktmp = checkAI(x,y);
    if(checktmp == 4){
        cout << "AI HAS WON" << "!" << endl;
        system("pause");
        exit(0);
    }
    if(checktmp>=1&&checktmp<=3){
        if(rectmp == 1){
            int x1 = x+dx[tmpi];
            int y1 = y +dy[tmpi];
            while(true){
                if(x1>0&&y1>0&&x1<=20&&y1<=20&&vis[x1][y1]==2){
                    int x11 = x1-dx[tmpi];
                    int y11 = y1-dy[tmpi];
                    while(true){
                        if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==2){
                            break;
                        }
                        if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==1){
                            x11 = x11 - dx[tmpi];
                            y11 = y11 - dy[tmpi];
                            continue;
                        }
                        if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==0) {
                            vis[x11][y11] = 1;
                            map[x11][y11] = "1";
                            usedx = x11;
                            usedy = y11;
                            return;
                        }
                        x11 = x11 - dx[tmpi];
                        y11 = y11 - dy[tmpi];
                    }
                    break;
                }
                if(x1>0&&y1>0&&x1<=20&&y1<=20&&vis[x1][y1]==1){
                    x1 = x1 + dx[tmpi];
                    y1 = y1 + dy[tmpi];
                    continue;
                }
                if(x1>0&&y1>0&&x1<=20&&y1<=20&&vis[x1][y1]==0) {
                    vis[x1][y1] = 1;
                    map[x1][y1] = "1";
                    usedx = x1;
                    usedy = y1;
                    return;
                }
                x1 = x1 + dx[tmpi];
                y1 = y1 + dy[tmpi];
            }
        }if(rectmp == -1){
            int x1 = x-dx[tmpi];
            int y1 = y-dy[tmpi];
            while(true){
                if(x1>0&&y1>0&&x1<=20&&y1<=20&&vis[x1][y1]==2){
                    int x11 = x1+dx[tmpi];
                    int y11 = y1+dy[tmpi];
                    while(true){
                        if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==2){
                            break;
                        }
                        if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==1){
                            x11 = x11 + dx[tmpi];
                            y11 = y11 + dy[tmpi];
                            continue;
                        }
                        if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==0) {
                            vis[x11][y11] = 1;
                            map[x11][y11] = "1";
                            usedx = x11;
                            usedy = y11;
                            return;
                        }
                        x11 = x11 + dx[tmpi];
                        y11 = y11 + dy[tmpi];
                    }
                    break;
                }
                if(x1>0&&y1>0&&x1<=20&&y1<=20&&vis[x1][y1]==1){
                    x1 = x1 + dx[tmpi];
                    y1 = y1 + dy[tmpi];
                    continue;
                }
                if(x1>0&&y1>0&&x1<=20&&y1<=20&&vis[x1][y1]==0) {
                    vis[x1][y1] = 1;
                    map[x1][y1] = "1";
                    usedx = x1;
                    usedy = y1;
                    return;
                }
                x1 -= dx[tmpi];
                y1 -= dy[tmpi];
            }
        }
        for(int i = 1; i<20; i++){
            for(int j = 1; j<20; j++){
                if(couldVis[i][j]){
                    if(vis[i][j] == 2){
                        continue;
                    }
                    if(vis[i][j] == 1){
                        continue;
                    }
                    map[i][j] = "1";
                    vis[i][j] = 1;
                    usedx = i;
                    usedy = j;
                    return;
                }
            }
        }
        int m = -1;
        for(int i = 0; i<8; i++){
            int checkwaytmp = checkAI(x,y,i);
            if(checkwaytmp >=2){
                if(checkwaytmp == 300){
                    continue;
                }
                if(checkwaytmp == 200){
                    continue;
                }
                if(checkwaytmp > m){
                    m = checkwaytmp;
                    tmpii = i;
                }
            }
        }
        if(m >= 2){
            if(rectmp1 == 1){
                int xx = x+dx[tmpii];
                int yy = y+dy[tmpii];
                while(true){
                    if(xx>0&&yy>0&&xx<=20&&yy<=20&&vis[xx][yy]==0) {
                        vis[xx][yy] = 1;
                        map[xx][yy] = "1";
                        usedx = xx;
                        usedy = yy;
                        return;
                    }
                    if(xx>0&&yy>0&&xx<=20&&yy<=20&&vis[xx][yy]==2){
                        int x11 = xx-dx[tmpi];
                        int y11 = yy-dy[tmpi];
                        while(true){
                            if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==2){
                                break;
                            }
                            if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==1){
                                x11 = x11 - dx[tmpi];
                                y11 = y11 - dy[tmpi];
                                continue;
                            }
                            if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==0) {
                                vis[x11][y11] = 1;
                                map[x11][y11] = "1";
                                usedx = x11;
                                usedy = y11;
                                return;
                            }
                            x11 = x11 - dx[tmpi];
                            y11 = y11 - dy[tmpi];
                        }
                        break;
                    }
                    xx = xx + dx[tmpii];
                    yy = yy + dy[tmpii];
                }
            }
            if(rectmp1 == -1){
                int xx1 = x-dx[tmpii];
                int yy1 = y-dy[tmpii];
                while(true){
                    if(xx1>0&&yy1>0&&xx1<=20&&yy1<=20&&vis[xx1][yy1]==0) {
                        vis[xx1][yy1] = 1;
                        map[xx1][yy1] = "1";
                        usedx = xx1;
                        usedy = yy1;
                        return;
                    }
                    if(xx1>0&&yy1>0&&xx1<=20&&yy1<=20&&vis[xx1][yy1]==2){
                        int x11 = xx1+dx[tmpi];
                        int y11 = yy1+dy[tmpi];
                        while(true){
                            if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==2){
                                break;
                            }
                            if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==1){
                                x11 = x11 + dx[tmpi];
                                y11 = y11 + dy[tmpi];
                                continue;
                            }
                            if(x11>0&&y11>0&&x11<=20&&y11<=20&&vis[x11][y11]==0) {
                                vis[x11][y11] = 1;
                                map[x11][y11] = "1";
                                usedx = x11;
                                usedy = y11;
                                return;
                            }
                            x11 = x11 + dx[tmpi];
                            y11 = y11 + dy[tmpi];
                        }
                        break;
                    }
                    xx1 = xx1 - dx[tmpii];
                    yy1 = yy1 - dy[tmpii];
                }
            }
        }
        for(int i = 0; i<8; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx>0&&yy>0&&xx<=20&&yy<=20&&vis[xx][yy]==0){
                vis[xx][yy] = 1;
                map[xx][yy] = "1";
                usedx = xx;
                usedy = yy;
                return;
            }
        }
    }
}

int main(){
    cout << "This is V1.2.3"<<endl;
    for(int i = 1; i<=20; i++){
        for(int j = 1; j<=20; j++){
            map[i][j] = ".";
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i<=20; i++){
        map[0][i] = to_string(cnt1);
        cnt1++;
    }
    for(int i = 0; i<=20; i++){
        map[i][0] = to_string(cnt2);
        cnt2++;
    }

    bool k;
    map[10][10] = "1";
    vis[10][10] = 1;
    print();
    int tmpx1,tmpy1;
    k = true;
    while(steps <= 50000){
        if(steps == 1){
            while(true){
                int number;
                srand(time(nullptr));
                number = rand() % 8;
                if(number==8){
                    continue;
                }else{
                    int x1 = 10+dx[number];
                    int y1 = 10+dy[number];
                    if(x1>0&&y1>0&&x1<=20&&y1<=20&&vis[x1][y1]==0){
                        vis[x1][y1] = 1;
                        map[x1][y1] = "1";
                        tmpx1 = x1;
                        tmpy1 = y1;
                        break;
                    }else{
                        continue;
                    }
                }
            }
            steps++;
            k = true;
            print();
        }
        if(!k){
            run(tmpx1,tmpy1);
            print();
            tmpx1 = usedx;
            tmpy1 = usedy;
        }
        int tmpxxx,tmpyyy;
        cin >> tmpxxx >> tmpyyy;
        bool ok = false;
        while(!ok){
            if(vis[tmpxxx][tmpyyy] == 1){
                cout << "ERROR!" << "ENTER AGAIN: ";
                cin >> tmpxxx >> tmpyyy;
                continue;
            }
            if(vis[tmpxxx][tmpyyy] == 2) {
                cout << "ERROR!" << "ENTER AGAIN: ";
                cin >> tmpxxx >> tmpyyy;
                continue;
            }
            ok = true;
        }
        system("cls");
        map[tmpxxx][tmpyyy] = "2";
        vis[tmpxxx][tmpyyy] = 2;
        print();
        k = false;
        steps++;
    }
    return 0;
}
