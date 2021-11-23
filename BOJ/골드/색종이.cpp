#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>
using namespace std;
int N;
int paper[100][100];

int main(void)
{
    cin >> N;
    int x, y;

    memset(paper, 0, sizeof(paper));
    int ans = 0;
    for (int i = 0;i < N;i++)
    {
        cin >> x >> y;

        for (int j = x;j < x + 10;j++)
        {
            for (int k = y;k < y + 10;k++)
            {
                if (paper[j][k] == 0)
                {
                    paper[j][k] = 1;
                    ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
    
}
