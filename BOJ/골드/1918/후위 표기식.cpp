#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;

    cin >> s;

    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '+' || s[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == '/' || s[i] == '*') {
            while (!st.empty() && (st.top() != '+' && st.top() != '-' && st.top() != '(')) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else {
            cout << s[i];
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }


    return 0;
}
