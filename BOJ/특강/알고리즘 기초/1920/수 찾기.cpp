#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100000];

int main() {

    cin >> N;

    for (int i = 0;i < N;i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);

    scanf("%d", &M);
    int num, left, right, mid;
    for (int i = 0;i < M;i++)
    {
        scanf("%d", &num);

        left = 0;
        right = N - 1;

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (arr[mid] == num)
            {
                printf("1\n");
                break;
            }
            if (arr[mid] > num)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (left > right)
            printf("0\n");
    }
    return 0;
}
