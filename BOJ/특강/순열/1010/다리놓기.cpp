#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main(void)
{
    int l, r;
    int N;

    int bridge[31][31];
    bridge[1][1] = 1;

    for (int i = 1;i <= 30;i++)
        for (int j = 1;j <= 30;j++) {
            if (i == j)
                bridge[i][j] = 1;
            else if (i == 1)
                bridge[i][j] = j;
            else
                bridge[i][j] = 0;
        }

    scanf("%d", &N);

    vector<int> result;
    for (int i = 0;i < N;i++)
    {
        scanf("%d %d", &l, &r);

        if (bridge[l][r] > 0)
            result.push_back(bridge[l][r]);
        else
        {
            for (int j = 2;j <= l;j++)
            {
                for (int k = j + 1;k <= r;k++)
                    if(bridge[j][k] == 0)
                        bridge[j][k] = bridge[j][k - 1] + bridge[j - 1][k - 1];
            }
            result.push_back(bridge[l][r]);
        }
    }

    for (int i = 0;i < N;i++)
        printf("%d\n", result[i]);
    return 0;

}
