#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N;
string number;
int K;
int ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> K;

    cin >> number;

    ans = 0;
    deque<char> d;

    for (int i = 0; i < N; i++) {
        
        while (!d.empty() && K && d.back() < number[i]) {
            d.pop_back();
            K--;
        }
        d.push_back(number[i]);
    }
    
    for (int i = 0; i < d.size() - K; i++)
        cout << d[i];
    return 0;

}
