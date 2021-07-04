#include<iostream>
#include<math.h>

using namespace std;

int main(void)
{
	int n, k;

	cin >> n >> k;

	int count = 0;
	int num = 0;

	while (num < n)
	{
		num = pow(k, count);
		count++;
	}
	if (num > n) {
		num /= k;
		count--;
	}
	
	count = n - num + count - 1;

	cout << count << endl;

	return 0;
}
