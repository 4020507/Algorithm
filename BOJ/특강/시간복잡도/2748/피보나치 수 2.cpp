#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int N;
long long fibo[91];

int main() {
    cin >> N;
    
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2;i <= N;i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    cout << fibo[N];

    return 0;
}
