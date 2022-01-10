#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define MAX 1000000
int parent[MAX + 1];

int findParent(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = findParent(parent[a]);
}

void Union(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int M, N, i;
    cin >> N >> M;

    for (i = 0;i <= N;i++)
        parent[i] = i;

    int a, b, c;
    for (i = 0;i < M;i++)
    {
        cin >> a >> b >> c;

        if (a == 0)
        {
            Union(b, c);
        }
        else
        {

            if (findParent(b) == findParent(c))
            {
                cout << "YES" << '\n';
            }
            else
                cout << "NO" << '\n';
        }
    }
    
    
    return 0;

}
