#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int X, Y;

    cin >> X >> Y;

    int Z = (long long)100 * Y / X;

    int ans = -1;
    if (Z >= 99)
    {
        cout << ans;
        return 0;
    }
    int minimum = 0;
    int maximum = 1000000000;
    int mid;
    unsigned long long rate;

    while (minimum <= maximum)
    {
        mid = (minimum + maximum) / 2;
        rate = (100 * (long long)(Y + mid)) / (X + mid);
        if (Z < rate)
        {
            ans = mid;
            maximum = mid - 1;
        }
        else
            minimum = mid + 1;
    }

    cout << ans;

    return 0;
}
