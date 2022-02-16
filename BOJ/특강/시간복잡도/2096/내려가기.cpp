#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

int N;
int game[100000][3];
int maxDP[3];
int minDP[3];
int main() {
    cin >> N;
    
    for (int i = 0;i < N;i++)
    {
        cin >> game[i][0] >> game[i][1] >> game[i][2];
    }

    memset(maxDP, 0, sizeof(maxDP));
    memset(minDP, 0, sizeof(minDP));

    minDP[0] = maxDP[0] = game[0][0];
    minDP[1] = maxDP[1] = game[0][1];
    minDP[2] = maxDP[2] = game[0][2];
    int temp1,temp2;
    for (int i = 1;i < N;i++)
    {
        temp1 = maxDP[0]; temp2 = maxDP[2];
        maxDP[0] = max(maxDP[0], maxDP[1]) + game[i][0];
        maxDP[2] = max(maxDP[1], maxDP[2]) + game[i][2];
        maxDP[1] = max(maxDP[1], max(temp1, temp2)) + game[i][1];

        temp1 = minDP[0]; temp2 = minDP[2];
        minDP[0] = min(minDP[0], minDP[1]) + game[i][0];
        minDP[2] = min(minDP[1], minDP[2]) + game[i][2];
        minDP[1] = min(temp1, min(temp2, minDP[1])) + game[i][1];
    }

    cout << max(maxDP[0], max(maxDP[1], maxDP[2])) << ' ' << min(minDP[0], min(minDP[1], minDP[2]));

    return 0;
}
