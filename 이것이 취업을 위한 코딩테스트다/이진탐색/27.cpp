#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int nums[1000000];
int main(void) {

    int N,x;
    cin >> N >> x;

    for (int i = 0;i < N;i++)
        cin >> nums[i];

    int left = 0;
    int right = N - 1;
    int mid;

    bool possible = false;

    while (left<=right)
    {
        mid = (left + right) / 2;

        if (nums[mid] > x)
        {
            right = mid - 1;
        }
        else if (nums[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            possible = true;
            break;
        }
    }

    if (!possible)
        cout << -1 << endl;
    else
    {
        int count = 0;

        for (int i = mid;i < N && x == nums[i];i++)
        {
            count++;
        }

        for (int i = mid - 1;i >= 0 && nums[i] == x;i--)
        {
            count++;
        }

        cout << count << '\n';
    }
    

    return 0;
    
}
