#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
#include <vector>
using namespace std;

int n, k;
string card[10];
set<string> s;
bool visited[10];
void dfs(int K, vector<string>& v)
{
    if (K == 0)
    {
        string str = "";
        for (auto t : v)
            str += t;
        s.insert(str);
        return;
    }

    for (int i = 0;i < n;i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(card[i]);
            dfs(K - 1, v);
            v.pop_back();
            visited[i] = false;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0;i < n;i++)
        cin >> card[i];
    memset(visited, false, sizeof(visited));
    vector<string> v;
    dfs(k, v);
    cout << s.size();
    return 0;

}

