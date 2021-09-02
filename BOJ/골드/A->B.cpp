#include<iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int init;
int target;
int ans;
int main(int argc, char** argv)
{
    cin >> init >> target;
    ans = 0;

    while (init < target)
    {
        if (target % 10 == 1)
        {
            target /= 10;
            ans++;
            continue;
        }
        else if (target % 2 == 0)
        {
            target /= 2;
            ans++;
            continue;
        }
        break;
    }

    if (init == target)
        cout << ans + 1;
    else
        cout << -1;

    return 0;
}
