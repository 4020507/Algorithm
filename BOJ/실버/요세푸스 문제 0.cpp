#include <iostream>
#include <string.h>
using namespace std;

int circle[1001];
int nums[1000];
int N;
int K;
int find(int idx)
{
    int start = 0;
    while (1)
    {
        if (circle[idx] != 0)
        {
            start++;
            if (start == K)
            {
                circle[idx] = 0;
                return idx;
            }
        }

        idx++;
        if (idx == N + 1)
            idx = 1;
    }

    return -1;
}

int main(int argc, const char* argv[]) {

    cin >> N >> K;

    for (int i = 1;i <= N;i++)
    {
        circle[i] = i;
    }

    int idx = 1;
    int start = 0;
    while (1)
    {
        idx = find(idx);

        if (idx == -1)
            break;
        nums[start] = idx;
        start++;
        idx++;

        if (start == N)
            break;
        if (idx == N + 1)
            idx = 1;

        while (circle[idx] == 0)
        {
            idx++;
            if (idx == N + 1)
                idx = 1;
        }
    }

    cout << '<';
    for (int i = 0;i < N;i++) {
        if (i != N - 1)
            cout << nums[i] << ", ";
        else
            cout << nums[i] << '>';
    }

    return 0;
}
