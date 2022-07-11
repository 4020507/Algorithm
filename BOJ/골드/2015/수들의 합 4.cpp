#pragma warning(disable:4996)
#include <iostream>
#include <map>

using namespace std;

int N;
long long sum[200001];
map<int, long long> m;
int K;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> K;
    long long num;
    long long ans = 0;
    m[0] = 1;

    for (int i = 1; i <= N; i++) {
        cin >> num;

        sum[i] = sum[i - 1] + num;

        ans += m[sum[i] - K];

        m[sum[i]]++;
    }

    cout << ans;

    return 0;

}
