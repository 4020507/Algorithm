#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int matrix[51][51];
int matrix1[51][51];
int N, M;
vector<pair<pair<int,int>,int>> seq;

void turn(int r, int c, int s) {

    int i, j, k;
    int temp1, temp2;

    for (k = s; k > 0; k--) {

        temp1 = matrix[r - k][c - k];

        for (i = r - k; i <= r + k - 1;i++) {
            matrix[i][c - k] = matrix[i + 1][c - k];
        }

        temp2 = matrix[r - k][c + k];
        for (j = c + k; j >= c - k + 1; j--) {
            matrix[r - k][j] = matrix[r - k][j - 1];
        }
        matrix[r - k][c - k + 1] = temp1;

        temp1 = matrix[r + k][c + k];

        for (i = r + k; i >= r - k + 1; i--) {
            matrix[i][c + k] = matrix[i - 1][c + k];
        }
        matrix[r - k + 1][c + k] = temp2;

        for (j = c - k; j <= c + k - 1; j++) {
            matrix[r + k][j] = matrix[r + k][j + 1];
        }
        matrix[r + k][c + k - 1] = temp1;

    }
}

int score() {
    int sum1 = 1e9;
    int sum2;
    int i, j;

    for (i = 1; i <= N; i++) {
        sum2 = 0;
        for (j = 1; j <= M; j++) {
            sum2 += matrix[i][j];
        }

        sum1 = min(sum1, sum2);
    }

    return sum1;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, r, c, s;

    cin >> N >> M >> k;

    int i, j;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            cin >> matrix1[i][j];
        }
    }


    for (i = 0; i < k; i++) {
        cin >> r >> c >> s;

        seq.push_back({ {r,c},s });
    }

    sort(seq.begin(), seq.end());

    int ans = 1e9;

    do {
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= M; j++) {
                matrix[i][j] = matrix1[i][j];
            }
        }
        for (i = 0; i < k; i++) {
            turn(seq[i].first.first, seq[i].first.second, seq[i].second);
            
        }

        ans = min(ans, score());

    } while (next_permutation(seq.begin(), seq.end()));

    cout << ans;


    return 0;
}
