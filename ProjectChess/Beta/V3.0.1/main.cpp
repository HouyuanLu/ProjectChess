#include <iostream>
#include <string>
#include "Functions.h"
#include "AttackMain.h"
#include "DefendMain.h"
#define CB 25
#define CEN 13
using namespace std;
/*h227N*/
//todo: Couldvis Function defend
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
                finished = false;
                return;
            }
        }
    }
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
                finished = false;
                return;
            }
        }
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
    //h137ND
    cout << "This is Beta V.3.0.1" << endl;
    reset();
    cout << "Please select your mode: " << endl;
    cout << "1. Human VS. AI" << endl;
    cout << "2. FREESTYLE" << endl;
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
            if(steps<=5){
                cout << "Enter where you want to place the piece (Enter / help to enter the help utility): " << endl;
            }else{
                cout << "Enter where you want to place the piece: " << endl;
            }
            cin >> tmpxxx >> tmpyyy;
            while (!ok) {
                if(tmpxxx == "/" && tmpyyy == "help"){
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
        map[0][0] = "0";
        bool Fin = false;
        while (steps <= 500000) {
            if(steps%2==0){
                bool ok = false;
                string tmpxxx, tmpyyy;
                print();
                cout << "Enter where you want to place the piece (Enter / ret to retreat): " << endl;
                cin >> tmpxxx >> tmpyyy;
                while (!ok) {
                    if(tmpxxx == "/" && tmpyyy == "ret"){
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
                steps++;
            }else{
                bool ok = false;
                string tmpxxx, tmpyyy;
                print();
                cout << "Enter where you want to place the piece (Enter / ret to retreat): " << endl;
                cin >> tmpxxx >> tmpyyy;
                while (!ok) {
                    if(tmpxxx == "/" && tmpyyy == "ret"){
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
                steps++;
            }
        }
    }
    return 0;
}