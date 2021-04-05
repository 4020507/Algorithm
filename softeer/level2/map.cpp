#include <stdio.h>

int main(void)
{
        int level;
        scanf("%d",&level);

       int init = 2;

       for(int i = 0;i<level;i++)
                init = init * 2 - 1;
        printf("%d\n",init * init);
        return 0;
}
