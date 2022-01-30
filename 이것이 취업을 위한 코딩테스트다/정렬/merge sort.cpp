#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int sorted[10];
int arr[10] = { 2,3,5,1,4,8,9,6,7,1 };
void merge_sort(int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            sorted[k] = arr[i++];
        else
            sorted[k] = arr[j++];
        k++;
    }

    if (i <= mid)
    {
        for (int idx = i;idx <= mid;idx++)
            sorted[k++] = arr[idx];
    }
    else
    {
        for (int idx = j;idx <= end;idx++)
            sorted[k++] = arr[idx];
    }

    for (int i = start;i <= end;i++)
        arr[i] = sorted[i];
}
void merge(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge(start, mid);
        merge(mid+1, end);
        merge_sort(start, mid, end);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    
    merge(0, 9);

    for (int i = 0;i < 10;i++)
        cout << arr[i] << ' ';
    return 0;
}
