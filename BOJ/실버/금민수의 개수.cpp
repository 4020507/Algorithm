#include <iostream>

using namespace std;

long long a, b, ans;

void dfs(long long start)
{
    if (start > b)
        return;

    if (start >= a)
        ans++;
    dfs(start * 10 + 4);
    dfs(start * 10 + 7);
}
int main(int argc, const char* argv[]) {
    
    cin >> a >> b;

    ans = 0;

    dfs(0);

    cout << ans;

    return 0;
}
