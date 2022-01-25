#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[10] = { 1,5,2,4,3,2,5,7,9,8 };

void heapify(int i, int n)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(largest, n);
    }
}

void heapsort()
{
    for (int i = N / 2;i >= 0;i--)
        heapify(i, N);

    for (int i = N - 1;i >= 1;i--)
    {
        swap(arr[i], arr[0]);
        heapify(0, i);
    }

    for (int i = 0;i < N;i++)
        cout << arr[i] << ' ';
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    N = 10;
    heapsort();
    return 0;

}
