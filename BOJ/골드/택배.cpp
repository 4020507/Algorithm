#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int n, m;
int matrix[201][201];
int load[201][201];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    int a, b, c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                load[i][j] = 1e9;
            else {
                load[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        load[a][b] = c;
        load[b][a] = c;
        matrix[a][b] = b;
        matrix[b][a] = a;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (load[i][j] > load[i][k] + load[k][j]) {
                    load[i][j] = load[i][k] + load[k][j];
                    matrix[i][j] = matrix[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] != 0)
                cout << matrix[i][j] << ' ';
            else
                cout << '-' << ' ';
        }
        cout << '\n';
    }
    return 0;

}
