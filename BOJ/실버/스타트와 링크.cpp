#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int scoreboard[20][20];
int N;
int diff = 1e9;

void dfs(vector<int> start, vector<int> link, int i)
{
    if (start.size() + link.size() == N)
    {
        if (start.size() != link.size())
            return;

        int s = 0;
        int l = 0;

        for (int i = 0;i < start.size();i++)
        {
            for (int j = i + 1;j < start.size();j++)
            {
                s += scoreboard[start[i]][start[j]] + scoreboard[start[j]][start[i]];
            }
        }

        for (int i = 0;i < link.size();i++)
        {
            for (int j = i+1;j < link.size();j++)
            {
                l += scoreboard[link[i]][link[j]] + scoreboard[link[j]][link[i]];
            }
        }

        diff = min(diff, abs(s - l));

        return;
    }

    if (i == N)
        return;

        start.push_back(i);
        dfs(start, link, i + 1);
        start.pop_back();

        link.push_back(i);
        dfs(start, link, i + 1);
    
    
    
}

int main() {
    
    cin >> N;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            cin >> scoreboard[i][j];
    }
    vector<int> start, link;
    dfs(start,link,0);

    cout << diff;
    return 0;
}
