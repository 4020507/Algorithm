#pragma warning(disable:4996)
#include <iostream>
#include <string.h>

using namespace std;

long long dp[11][11][11][11][11][7][7];

long long getAns(int a, int b, int c, int d, int e, int color1, int color2) {

    if (a == -1 || b == -1 || c == -1 || d == -1 || e == -1)
        return 0;


    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
        return 1;
    }

    if (dp[a][b][c][d][e][color1][color2] != -1)
        return dp[a][b][c][d][e][color1][color2];
    
    long long& ret = dp[a][b][c][d][e][color1][color2];
    ret = 0;
    
    if(color1 != 0 && color2 != 0)
        ret += getAns(a - 1, b, c, d, e, color2, 0);
    if (color1 != 1 && color2 != 1)
        ret += getAns(a, b - 1, c, d, e, color2, 1);
    if (color1 != 2 && color2 != 2)
        ret += getAns(a, b, c - 1, d, e, color2, 2);
    if (color1 != 3 && color2 != 3)
        ret += getAns(a, b, c, d - 1, e, color2, 3);
    if (color1 != 4 && color2 != 4)
        ret += getAns(a, b, c, d, e - 1, color2, 4);

    return ret;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int num[5], N;

    memset(num, 0, sizeof(num));
    memset(dp, -1, sizeof(dp));

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    
   
    cout << getAns(num[0], num[1], num[2], num[3], num[4], 5, 6);

    return 0;

}
