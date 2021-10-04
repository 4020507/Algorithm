#include<iostream>

#pragma warning(disable:4996)
using namespace std;


int main(int argc, char** argv)
{
	int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
	int n = 10;
	int i = 0;

	while (i < n)
	{
		int min = arr[i];
		int k = i;
		for (int j = i + 1;j < n;j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				k = j;
			}
		}
		swap(arr[i], arr[k]);
		i++;
	}

	for (int i = 0;i < 10;i++)
		cout << arr[i] << ' ';
	return 0;
}
