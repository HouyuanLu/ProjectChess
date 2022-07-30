#include "Functions.h"
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
                tmpans = 0;
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
                tmpans = 0;
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
    }
    if (tmpans > m && tmpans > 0) {
        m = tmpans;
        rectmp = -1;
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