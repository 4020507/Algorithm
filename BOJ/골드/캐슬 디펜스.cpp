#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N, M, D;

int archors[3];
int matrix[15][15];
int temp[15][15];
int ans;
int enemies;
int alives;
int killed;
void down() {

    for (int i = N - 1;i > 0;i--) {
        for (int j = 0;j < M;j++) {
            if (i == N-1 && temp[i][j] == 1)
                alives--;

            temp[i][j] = temp[i - 1][j];
        }
    }
    for (int j = 0;j < M;j++)
        temp[0][j] = 0;
}
bool killEnemies() {
    
    int x = N;
    int y;
    int dist;
    int d;
    vector<pair<int, int>> v;
    pair<int, int> coord;
    for (int k = 0;k < 3;k++) {
        y = archors[k];
        d = 1e9;
        coord.second = M;
        for (int i = N - 1;i >= 0;i--) {
            for (int j =0 ;j < M;j++) {
                if (temp[i][j] == 1) {
                    dist = abs(i - N) + abs(y - j);
                    if (dist <= D) {
                        if (dist > d)
                            continue;
                        if (dist < d) {
                            d = dist;
                            coord.first = i;
                            coord.second = j;
                            continue;
                        }
                        if (j < coord.second) {
                            coord.first = i;
                            coord.second = j;
                        }
                    }
                }
            }
        }
        if (d != 1e9) {
            v.push_back({ coord.first,coord.second});
        }
    }

    for (int i = 0;i < v.size();i++) {
        if (temp[v[i].first][v[i].second] == 1) {
            killed++;
            alives--;
            temp[v[i].first][v[i].second] = 0;
        }
    }
    ans = max(ans, killed);
    
    if (alives <= 0)
        return false;
    return true;
}
void copyMatrix() {
    for (int i = 0;i < N;i++) 
        for (int j = 0;j < M;j++)
            temp[i][j] = matrix[i][j];  
}
void archorsPosition() {
    for (int i = 0;i < M;i++) {
        archors[0] = i;
        for (int j = 0;j < M;j++) {

            if (i == j)
                continue;
            archors[1] = j;

            for (int k = 0;k < M;k++) {
                if (i == k || j == k)
                    continue;
                archors[2] = k;

                copyMatrix();
                alives = enemies;
                killed = 0;
                while (killEnemies()) {
                    down();
                }
                
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ans = 0;
    enemies = 0;

    cin >> N >> M >> D;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
                enemies++;
        }
    }

    archorsPosition();
    cout << ans;

    return 0;

}
