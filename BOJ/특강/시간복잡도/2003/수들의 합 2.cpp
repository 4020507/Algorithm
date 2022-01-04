#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int N, M;
int arr[10000];
int ans;
int main() {
    cin >> N >> M;

    for (int i = 0;i < N;i++)
    {
        cin >> arr[i];
    }

    ans = 0;

    int left = 0;
    int right = 0;
    int sum = 0;
    while (left <= right && right <= N)
    {
        if (sum >= M)
        {
            if(sum == M)
                ans++;
            sum -= arr[left++];
        }
        else {
            if (right == N)
                break;
            sum += arr[right++];
        }
    }
    cout << ans;

    return 0;
}
