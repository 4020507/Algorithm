#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> v;
bool complete;

bool check(int x, int y, int num) {
    int i, j;

    for (i = 0; i < 9; i++) {
        if (sudoku[x][i] == num && i != y) {
            return false;
        }
    }

    for (i = 0; i < 9; i++) {
        if (sudoku[i][y] == num && i != x) {
            return false;
        }
    }


    for (i = x / 3 * 3; i < x / 3 * 3 + 3; i++) {
        for (j = y / 3 * 3; j < y / 3 * 3 + 3; j++) {

            if (i == x && y == j) {
                continue;
            }

            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }

    return true;

}

void dfs(int depth) {

    if (depth == v.size()) {
        complete = true;
        return;
    }

    for (int k = 1; k <= 9; k++) {


        if (check(v[depth].first, v[depth].second, k)) {
            sudoku[v[depth].first][v[depth].second] = k;
            dfs(depth + 1);

            if (complete) {
                return;
            }

            sudoku[v[depth].first][v[depth].second] = 0;
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    int i, j;

    string s;

    for (i = 0; i < 9; i++) {
        cin >> s;

        for (j = 0; j < 9; j++) {
            sudoku[i][j] = s[j] - '0';

            if (sudoku[i][j] == 0) {
                v.push_back({ i,j });
            }
        }
    }

    complete = false;

    dfs(0);

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cout << sudoku[i][j];
        }

        cout << '\n';
    }

    return 0;
}
