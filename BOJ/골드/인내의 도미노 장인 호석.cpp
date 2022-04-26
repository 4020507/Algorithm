#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

bool state[101][101];
int dominoes[101][101];
int N, M, R;
int score;

void push(int x, int y, char dir) {
    if (!state[x][y])
        return;
    int height;
    if (dir == 'E') {
        height = y + dominoes[x][y];

        for (int i = y;i < height && i <= M;i++) {
            if (state[x][i]) {
                score++;
                state[x][i] = false;

                if (height < i + dominoes[x][i])
                    height = i + dominoes[x][i];
            }
        }
    }
    else if (dir == 'W') {
        height = y - dominoes[x][y];

        for (int i = y;i > height && i > 0;i--) {
            if (state[x][i]) {
                score++;
                state[x][i] = false;

                if (height > i - dominoes[x][i])
                    height = i - dominoes[x][i];
            }
        }
    }
    else if (dir == 'S') {
        height = x + dominoes[x][y];

        for (int i = x;i < height &&i <= N;i++) {
            if (state[i][y]) {
                score++;
                state[i][y] = false;

                if (height < i + dominoes[i][y])
                    height = i + dominoes[i][y];
            }
        }
    }
    else if (dir == 'N') {
        height = x - dominoes[x][y];

        for (int i = x;i > height && i > 0;i--) {
            if (state[i][y]) {
                score++;
                state[i][y] = false;

                if (height > i - dominoes[i][y]) {
                    height = i - dominoes[i][y];
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M >> R;

    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++)
            cin >> dominoes[i][j];

    int x, y;
    char dir;
    score = 0;
    memset(state, true, sizeof(state));

    for (int i = 0;i < R * 2;i++) {

        if (i % 2 == 0) {
            cin >> x >> y >> dir;
            push(x, y, dir);
        }
        else {
            cin >> x >> y;
            state[x][y] = true;
        }
            
    }

    cout << score<<'\n';

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= M;j++) {
            if (state[i][j])
                cout << "S ";
            else
                cout << "F ";
        }
        cout << '\n';
    }
    return 0;

}
