#include <iostream>

using namespace std;
int dp[12];
int main(int argc, const char* argv[]) {
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;


    for (int i = 4;i <= 11;i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    int T;
    cin >> T;
    int N;
    for (int test_case = 0;test_case < T;test_case++)
    {
        cin >> N;

        cout << dp[N] << '\n';
    }
    return 0;
}
