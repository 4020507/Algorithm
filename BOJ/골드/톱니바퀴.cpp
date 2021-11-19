#pragma warning(disable: 4996)
#include <iostream>
#include <stdio.h>
using namespace std;
int one[8];
int two[8];
int three[8];
int four[8];

bool d1;
bool d2;
bool d3;
bool d4;

void clockwise(int *arr)
{
    int temp = arr[7];

    for (int i = 6;i >= 0;i--)
        arr[i+1] = arr[i];
    arr[0] = temp;
}

void anticlockwise(int* arr)
{
    int temp = arr[0];
    for (int i = 0;i < 7;i++)
        arr[i] = arr[i+1];
    arr[7] = temp;
}

void compare(int num, int dir)
{
    if (num == 1)
    {
        d1 = true;
        d2 = false;
        d3 = false;
        d4 = false;
        if (one[2] != two[6])
        {
            d2 = true;

            if (two[2] != three[6])
            {
                d3 = true;

                if (three[2] != four[6])
                    d4 = true;
            }
        }
    }
    else if (num == 2)
    {
        d1 = false;
        d2 = true;
        d3 = false;
        d4 = false;

        if (two[2] != three[6])
        {
            d3 = true;

            if (three[2] != four[6])
                d4 = true;
        }

        if (one[2] != two[6])
            d1 = true;
    }
    else if (num == 3)
    {
        d1 = false;
        d2 = false;
        d3 = true;
        d4 = false;

        if (three[2] != four[6])
        {
            d4 = true;
        }

        if (two[2] != three[6])
        {
            d2 = true;

            if (one[2] != two[6])
                d1 = true;
        }
    }
    else if (num == 4)
    {
        d1 = false;
        d2 = false;
        d3 = false;
        d4 = true;

        if (four[6] != three[2])
        {
            d3 = true;

            if (three[6] != two[2])
            {
                d2 = true;

                if (two[6] != one[2])
                    d1 = true;
            }
        }
    }
}
int main(void)
{
    
    int K;
    int num;
    int dir;

    for (int i = 0;i < 8;i++)
        scanf("%1d", &one[i]);
    for (int i = 0;i < 8;i++)
        scanf("%1d", &two[i]);
    for (int i = 0;i < 8;i++)
        scanf("%1d", &three[i]);
    for (int i = 0;i < 8;i++)
        scanf("%1d", &four[i]);

    cin >> K;

    for (int i = 0;i < K;i++)
    {
        cin >> num >> dir;

        compare(num, dir);


        if (num == 1)
        {
            if (dir == 1)
            {
                clockwise(one);
                
                if (d2)
                    anticlockwise(two);
                if (d3)
                    clockwise(three);
                if (d4)
                    anticlockwise(four);
            }
            else
            {
                anticlockwise(one);

                if (d2)
                    clockwise(two);
                if (d3)
                    anticlockwise(three);
                if (d4)
                    clockwise(four);
            }
        }
        else if (num == 2)
        {
            if (dir == 1)
            {
                clockwise(two);

                if (d1)
                    anticlockwise(one);
                if (d3)
                    anticlockwise(three);
                if (d4)
                    clockwise(four);
            }
            else
            {
                anticlockwise(two);

                if (d1)
                    clockwise(one);
                if (d3)
                    clockwise(three);
                if (d4)
                    anticlockwise(four);
            }
        }
        else if (num == 3)
        {
            if (dir == 1)
            {
                clockwise(three);

                if (d1)
                    clockwise(one);
                if (d2)
                    anticlockwise(two);
                if (d4)
                    anticlockwise(four);
            }
            else
            {
                anticlockwise(three);

                if (d1)
                    anticlockwise(one);
                if (d2)
                    clockwise(two);
                if (d4)
                    clockwise(four);
            }
        }
        else if (num == 4)
        {
            if (dir == 1)
            {
                clockwise(four);

                if (d1)
                    anticlockwise(one);
                if (d2)
                    clockwise(two);
                if (d3)
                    anticlockwise(three);
            }
            else
            {
                anticlockwise(four);

                if (d1)
                    clockwise(one);
                if (d2)
                    anticlockwise(two);
                if (d3)
                    clockwise(three);
            }
        }
    }

    cout << one[0] + two[0] * 2 + three[0] * 4 + four[0] * 8;

    return 0;
    
}
