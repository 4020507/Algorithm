#pragma warning(disable:4996)
#include<iostream>

using namespace std;


int arr[10] = { 1,5,2,4,7,8,9,3,6 };
int n = 10;

void quicksort(int start, int end, int* arr)
{
	if (start >= end)
		return;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (arr[pivot] > arr[left] && left<10)
			left++;
		while (arr[pivot] < arr[right] && right > pivot)
			right--;

		if (left < right)
			swap(arr[left], arr[right]);
		else
			swap(arr[pivot], arr[right]);
	}

	quicksort(start, right - 1, arr);
	quicksort(right + 1, end, arr);
}

int main(void) 
{
	quicksort(0, n - 1, arr);
	for (int i = 0;i < n;i++)
		cout << arr[i] << endl;
	
	return 0;
}
