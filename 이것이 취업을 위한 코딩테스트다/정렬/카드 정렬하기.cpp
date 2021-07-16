#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


int main(void) {

    int N;
    cin >> N;

    priority_queue <int> pq;

    for (int i = 0;i < N;i++)
    {
        int a;
        cin >> a;
        pq.push(-a);
    }

    int result = 0;

    while (1)
    {
        int a = pq.top();
        pq.pop();

        if (pq.empty())
        {
            cout << result << '\n';
            break;
        }
        int b = pq.top();
        pq.pop();
        result += (-a + -b);
        pq.push(a + b);
    }
    return 0;
    
}
