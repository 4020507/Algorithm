#include<iostream>
#include<queue>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int N, K;
bool visited[100001];
int ans;

int main(int argc, char** argv)
{
    cin >> N >> K;

    memset(visited, false, sizeof(visited));
    priority_queue<pair<int,int>> q;
    q.push({ 0,N });
    int time = 1e9;
    int count = 0;

    while (!q.empty())
    {
        int a = -q.top().first;
        int b = q.top().second;
        q.pop();
        if (b == K)
        {
            if (time == a)
            {
                count++;
            }
            else if (time > a)
            {
                time = a;
                count = 1;
            }
            else if (time < a)
            {
                break;
            }
            continue;
        }

        visited[b] = true;

        if (b - 1 >= 0 && !visited[b - 1])
        {
            q.push({ -a - 1,b - 1 });
        }
        if (b + 1 <= 100000 && !visited[b + 1])
        {
            q.push({ -a - 1,b + 1 });
        }
        if (b * 2 < 100001 && !visited[b * 2])
        {
            q.push({ -a - 1,b * 2 });
        }
    }

    cout << time << '\n';
    cout << count;
    return 0;
}
