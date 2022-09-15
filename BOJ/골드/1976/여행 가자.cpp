#include<iostream>
#include<string.h>
#include<vector>
#include<string>
using namespace std;

int cities[201][201];
int route[1000];
int N, i, j, M;
bool visited[201];
string ans;

void journey(int curr, int purpose, int index) {

    if (curr == purpose) {
        if (index == M - 1) {
            ans = "YES";
            return;
        }

        memset(visited, false, sizeof(visited));
        visited[curr] = true;
        journey(curr, route[index + 1], index + 1);
    }

    for (int i = 1; i <= N; i++) {
        if (cities[curr][i] == 1 && !visited[i]) {
            visited[i] = true;
            journey(i, purpose, index);
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            cin >> cities[i][j];

        }
    }

    for (i = 0; i < M; i++) {
        cin >> route[i];
    }

    ans = "NO";
    journey(route[0], route[0], 0);

    cout << ans;

    return 0;
}
