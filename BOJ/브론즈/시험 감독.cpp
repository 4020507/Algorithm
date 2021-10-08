#include <iostream>
#include <algorithm>

using namespace std;

long long test[1000000];
int B, C;
int N;
int main(int argc, const char* argv[]) {

    cin >> N;

    for (int i = 0;i < N;i++)
        cin >> test[i];

    cin >> B >> C;

    long long ans = 0;

    sort(test, test + N);

    long long start = B;
    long long count = 1;
    for (int i = 0;i < N;i++)
    {
        test[i] -= start;

        if (test[i] <= 0)
        {
            ans += count;
        }
        else
        {
            long long quotient = test[i] / C;
            long long remains = test[i] % C;
            if (remains == 0)
            {
                start += quotient * C;
                count += quotient;
                ans += count;
            }
            else
            {
                start += (quotient+1) * C;
                count += quotient + 1;
                ans += count;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
