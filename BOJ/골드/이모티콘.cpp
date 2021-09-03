#include<iostream>
#include<queue>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int S;
bool visited[1001][1001];
int ans;

class smile
{
public:
    int screen;
    int clipboard;
    int count;
};
int main(int argc, char** argv)
{
    cin >> S;

    memset(visited, false, sizeof(visited));
    queue < smile> q;

    q.push({ 1,0,0 });
    int ans;
    while (!q.empty())
    {
        int screen = q.front().screen;
        int clipboard = q.front().clipboard;
        int count = q.front().count;

        if (screen == S)
        {
            ans = count;
            break;
        }

        if (screen < 1001 && screen >0)
        {
            if (!visited[screen - 1][clipboard])
            {
                q.push({ screen - 1,clipboard,count + 1 });
                visited[screen - 1][clipboard] = true;
            }
            if (clipboard > 0 && screen + clipboard < 1001)
            {
                if (!visited[screen + clipboard][clipboard])
                {
                    q.push({ screen + clipboard,clipboard,count + 1 });
                    visited[screen + clipboard][clipboard] = true;
                }
            }
            if (!visited[screen][screen])
            {
                q.push({ screen,screen,count + 1 });
                visited[screen][screen] = true;
            }

        }
        
        q.pop();
    }

    cout << ans;
    return 0;
}
