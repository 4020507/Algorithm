#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[2][1000];

int main() {
    int T, n, m;
    cin >> T;

    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> arr[0][i];

    int plus = 0;
    vector<int> arr1;
    for (int i = 0;i < n;i++)
    {
        plus = arr[0][i];
        arr1.push_back(plus);
        for (int j = i + 1;j < n;j++)
        {
            plus += arr[0][j];
            arr1.push_back(plus);
        }
    }

    cin >> m;
    for (int j = 0;j < m;j++)
        cin >> arr[1][j];

    vector<int> arr2;
    for (int i = 0;i < m;i++)
    {
        plus = arr[1][i];
        arr2.push_back(plus);
        for (int j = i + 1;j < m;j++)
        {
            plus += arr[1][j];
            arr2.push_back(plus);
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    long long ans = 0;
    for (auto a : arr1)
    {
        auto lb = lower_bound(arr2.begin(), arr2.end(), T - a);
        auto ub = upper_bound(arr2.begin(), arr2.end(), T - a);

        ans += (ub - lb);
    }

    cout << ans;
    return 0;
}
