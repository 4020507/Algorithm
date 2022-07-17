#pragma warning(disable:4996)
#include <iostream>
#include <string.h>

using namespace std;

int dist[401][401];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int v, e;

    cin >> v >> e;

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            dist[i][j] = 1e9;

    int a, b, c;

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int result = 1e9;

    for (int i = 1; i <= v; i++)
        result = min(result, dist[i][i]);

    if (result != 1e9)
        cout << result;
    else
        cout << -1;

    return 0;

}
