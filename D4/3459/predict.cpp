#include <stdio.h>
 
int main(void)
{
    int T;
    scanf("%d", &T);
    unsigned long x;
    unsigned long mul;
    unsigned long n;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf("%llu", &n);
        int check = 0;
        x = 1;
        mul = 1;
        while (x < n)
        {
            if (!check)
                mul *= 4;
            x += mul;
            check = !check;
        }
        printf("#%d %s\n", test_case,check?"Alice":"Bob");
            
 
    }
    return 0;
}
