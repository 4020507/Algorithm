#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int paper[10][10];

bool check(int x, int y, int range) {

    int i, j;

    if (x + range > 10 || y + range > 10) {
        return false;
    }

    for (i = x; i < x + range; i++) {
        for (j = y; j < y + range; j++) {
            if (paper[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

void covered(int x, int y, int range) {

    int i, j;

    for (i = x; i < x + range; i++) {
        for (j = y; j < y + range; j++) {
            paper[i][j] = 0;
        }
    }

}

void uncovered(int x, int y, int range) {

    int i, j;

    for (i = x; i < x + range; i++) {
        for (j = y; j < y + range; j++) {
            paper[i][j] = 1;
        }
    }

}


bool checkZero() {

    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (paper[i][j] == 1) {
                return false;
            }
        }
    }

    return true;
}
int ans;

void getAns(int one, int two, int three, int four, int five) {

    if (ans < one + two + three + four + five)
        return;
    
    if (one > 5 || two > 5 || three > 5 || four > 5 || five > 5) {
        return;
    }

    int i, j, k;

    if (checkZero()) {
        ans = one + two + three + four + five;

        return;
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (paper[i][j] == 1) {
                for (k = 5; k > 0; k--) {
                    if (check(i, j, k)) {
                        covered(i, j, k);
                        
                        switch (k) {
                        case 1:
                            getAns(one + 1, two, three, four, five);
                            break;
                        case 2:
                            getAns(one, two + 1, three, four, five);
                            break;
                        case 3:
                            getAns(one, two, three + 1, four, five);
                            break;
                        case 4:
                            getAns(one, two, three, four + 1, five);
                            break;
                        case 5:
                            getAns(one, two, three, four, five + 1);
                            break;
                        }

                        uncovered(i, j, k);
                    }
                }

                return;
            }
        }
    }



}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int i, j;

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            cin >> paper[i][j];

    ans = 500;
    getAns(0, 0, 0, 0, 0);

    if (ans != 500) {
        cout << ans;
    }
    else {
        cout << -1;
    }

    return 0;
}
