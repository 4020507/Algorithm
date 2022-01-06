#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

bool n[1000001];
int main(void)
{
    memset(n, false,sizeof(n));
    n[1] = true;

    for (int i = 2;i <= (int)sqrt(1000000);i++)
    {
        if (!n[i])
        {
            int j = 2;

            while (i*j <= 1000000)
            {
                n[i*j] = true;
                j++;
            }
        }
    }

    int num;
    bool check;
    while (1)
    {
        scanf("%d", &num);

        if (num == 0)
            break;
        check = false;
        for (int i = 3;i <= num - i;i+=2)
        {
            if (!n[i] && !n[num - i])
            {
                printf("%d = %d + %d\n", num, i, num - i);
                check = true;
                break;
            }
        }

        if (!check)
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;

}

