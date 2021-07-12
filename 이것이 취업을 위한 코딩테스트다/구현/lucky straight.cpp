#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int main(void) {
    
    int N;
    cin >> N;

    string num;
    cin >> num;

    int start = 0;
    int first = 0;
    int second = 0;
    for (int i = 0;i < N;i++)
    {
        if (start < N / 2)
        {
            start++;
            first += num[i] - '0';
        }
        else
        {
            second += num[i] - '0';
        }
    }

    if (first == second)
        cout << "LUCKY" << endl;
    else
        cout << "READY" << endl;

    return 0;
    
}
