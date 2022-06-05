#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int dist[401][401];
int cases[401][401];
int n, k, s;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                dist[i][j] = 1e9;
            else
                dist[i][j] = 0;
        }
    }

    int a, b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;

        dist[a][b] = -1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == -1 && dist[k][j] == -1) {
                    dist[i][j] = -1;
                    dist[j][i] = 1;
                }
            }
        }
    }

    cin >> s;


    for (int i = 0; i < s; i++) {
        cin >> a >> b;

        if (dist[a][b] == 1e9)
            cout << 0 << '\n';
        else
            cout << dist[a][b] << '\n';
    }
    return 0;

}
