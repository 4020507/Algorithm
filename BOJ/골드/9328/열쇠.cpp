#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    int N, M;
    char building[102][102];
    bool visited[102][102];
    bool key[26];
    int x, y, nx, ny;
    int i, j;
    int documents;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    string k;
    vector<pair<int,int>> door;
    int get;

    cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {

        cin >> N >> M;

        memset(key, false, sizeof(key));
        documents = 0;
        get = 0;

        for (i = 0; i <= N + 1; i++) {
            for (j = 0; j <= M + 1; j++) {
                
                if (i == 0 || i == N + 1 || j == 0 || j == M + 1) {
                    building[i][j] = '.';
                }
                else {
                    cin >> building[i][j];

                    if (building[i][j] == '$') {
                        documents++;
                    }
                }

                visited[i][j] = false;
            }
        }

        cin >> k;

        if (k != "0") {
            for (i = 0; i < k.length(); i++) {
                key[k[i] - 'a'] = true;
            }
        }

        queue<pair<int, int>> q;
        q.push({ 0,0 });
        visited[0][0] = true;
        door.clear();

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;

            q.pop();

            if (documents == get) {
                break;
            }

            for (i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];

                if (nx >= 0 && nx <= N + 1 && ny >= 0 && ny <= M + 1) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;

                        if (building[nx][ny] == '.') {
                            q.push({ nx,ny });
                        }
                        else if (building[nx][ny] >= 'a' && building[nx][ny] <= 'z') {
                            key[building[nx][ny] - 'a'] = true;
                            q.push({ nx,ny });

                            for (j = 0; j < door.size(); j++) {
                                if (building[nx][ny] - 'a' == building[door[j].first][door[j].second] - 'A') {
                                    q.push({ door[j].first,door[j].second });
                                }
                            }
                        }
                        else if (building[nx][ny] >= 'A' && building[nx][ny] <= 'Z') {
                            if (key[building[nx][ny] - 'A']) {
                                q.push({ nx,ny });
                            }
                            else {
                                door.push_back({ nx,ny });
                            }
                        }
                        else if (building[nx][ny] == '$') {
                            get++;
                            q.push({ nx,ny });
                        }
                    }
                }
            }
        }

        cout << get << '\n';
    }
    return 0;
}
