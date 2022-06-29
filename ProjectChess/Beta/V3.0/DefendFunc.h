#include "Functions.h"
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
