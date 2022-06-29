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