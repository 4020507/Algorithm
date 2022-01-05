#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    int N;
    string s;
    cin >> N;
    stack<int> st;
    int x;
    for (int i = 0;i < N;i++)
    {
        cin >> s;

        if (s == "push")
        {
            cin >> x;
            st.push(x);
        }
        else if (s == "pop")
        {
            if (st.size() == 0)
            {
                cout << -1 << '\n';
                continue;
            }
            else
                cout << st.top() << '\n';
            st.pop();
        }
        else if (s == "size")
        {
            cout << st.size() << '\n';
        }
        else if (s == "empty")
        {
            if (!st.empty())
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
        else if (s == "top")
        {
            if (st.size() == 0)
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
    }

    return 0;

}

