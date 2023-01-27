#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool isPrime[2000001];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    

    int T, i;

    cin >> T;

    int mul;

    memset(isPrime, true, sizeof(isPrime));

    vector<int> v;
    for (i = 2; i <= 2000000; i++) {
        if (isPrime[i]) {
            v.push_back(i);
            mul = 2;
            while (i*mul <= 2000000) {
                isPrime[i*mul] = false;
                mul++;
            }
        }
    }

    long long a, b, sum;

    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> a >> b;

        sum = a + b;

        if (sum <= 3) {
            cout << "NO" << '\n';
        }
        else {
            if (sum % 2 == 0) {
                cout << "YES" << '\n';
            }
            else {
                sum -= 2;

                if (sum <= 2000000) {
                    if (isPrime[sum]) {
                        cout << "YES" << '\n';
                    }
                    else {
                        cout << "NO" << '\n';
                    }
                }
                else {
                    for (i = 0; i < v.size(); i++) {
                        if (sum % v[i] == 0) {
                            cout << "NO" << '\n';
                            i = -1;
                            break;
                        }
                    }

                    if (i != -1) {
                        cout << "YES" << "\n";
                    }
                }
            }
        }
    }
    return 0;
}
