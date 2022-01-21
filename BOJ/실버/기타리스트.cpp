#include<iostream>
#include<string.h>

#pragma warning(disable:4996)
using namespace std;

int N, M, S;
int music[101];
bool volume[101][1001];
int main(int argc, char** argv)
{
    cin >> N >> S >> M;

    for (int i = 1;i <= N;i++)
        cin >> music[i];

    volume[0][S] = true;
    for (int i = 1;i <= N;i++)
    {
        for (int j = 0;j <= M;j++)
        {
            if (volume[i - 1][j])
            {
                if (j + music[i] <= M)
                {
                    volume[i][j + music[i]] = true;
                }
                if (j - music[i] >= 0)
                {
                    volume[i][j - music[i]] = true;
                }
            }
        }
    }

    for (int i = M;i >= 0;i--)
    {
        if (volume[N][i])
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
