#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int ans;

int buttons[10];
int digits;

bool possible(int num)
{
    string s = to_string(num);

    for (int i = 0;i<s.length();i++)
    {
        if (buttons[s[i] - 48] == -1)
            return false;
    }

    return true;
}
int main(int argc, const char* argv[]) {

    cin >> N >> M;

    ans = abs(100 - N);

    memset(buttons, 0, sizeof(buttons));
    for (int i = 0;i < M;i++)
    {
        int a;
        cin >> a;

        buttons[a] = -1;
    }
    
    for (int i = 0;i <= 1000000;i++)
    {
        if (possible(i))
        {
            ans = min(ans, (int)(abs(N - i) + to_string(i).length()));
        }
    }

    cout << ans;
    return 0;
}
