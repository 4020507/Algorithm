#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;


int main() {
    
    string s, ans;
    vector<string> order;
    vector<long long> NUM;
    int N, num;
    long long n1, n2;
    bool minus;
    int idx = 0;

    while (1)
    {
        cin >> s;

        if (s == "QUIT")
            break;

        order.clear();
        NUM.clear();
        while (1)
        {
            if (s == "END")
                break;
            if (s == "NUM")
            {
                long long temp;
                cin >> temp;
                NUM.push_back(temp);
            }

            order.push_back(s);
            cin >> s;
            
        }

        cin >> N;

        for (int i = 0;i < N;i++)
        {
            cin >> num;
            stack<long long> s;
            s.push(num);
            idx = 0;
            ans = "";
            for (int j = 0;j < order.size();j++)
            {
                minus = false;
                if (order[j] == "POP")
                {
                    if (s.size() == 0)
                    {
                        ans = "ERROR";
                        break;
                    }
                    s.pop();
                }
                else if (order[j] == "INV")
                {
                    if (s.size() == 0)
                    {
                        ans = "ERROR";
                        break;
                    }
                    n1 = -s.top();
                    s.pop();
                    s.push(n1);
                }
                else if (order[j] == "DUP")
                {
                    if (s.size() == 0)
                    {
                        ans = "ERROR";
                        break;
                    }
                    s.push(s.top());
                }
                else if (order[j] == "SWP")
                {

                    if (s.size() <= 1)
                    {
                        ans = "ERROR";
                        break;
                    }
                    n1 = s.top();
                    s.pop();
                    n2 = s.top();
                    s.pop();

                    s.push(n1);
                    s.push(n2);
                }
                else if (order[j] == "ADD")
                {
                    if (s.size() <= 1)
                    {
                        ans = "ERROR";
                        break;
                    }
                    n1 = s.top();
                    s.pop();
                    n2 = s.top();
                    s.pop();

                    n1 += n2;

                    if (n1 > 1000000000 || n1 < -1000000000)
                    {
                        ans = "ERROR";
                        break;
                    }
                    s.push(n1);
                }
                else if (order[j] == "SUB")
                {
                    if (s.size() <= 1)
                    {
                        ans = "ERROR";
                        break;
                    }
                    n1 = s.top();
                    s.pop();
                    n2 = s.top();
                    s.pop();

                    n2 -= n1;

                    if (n2 > 1000000000 || n2 < -1000000000)
                    {
                        ans = "ERROR";
                        break;
                    }
                    s.push(n2);
                }
                else if (order[j] == "MUL")
                {
                    if (s.size() <= 1)
                    {
                        ans = "ERROR";
                        break;
                    }

                    n1 = s.top();
                    s.pop();
                    n2 = s.top();
                    s.pop();

                    n1 *= n2;

                    if (n1 > 1000000000 || n1 < -1000000000)
                    {
                        ans = "ERROR";
                        break;
                    }
                    s.push(n1);
                }
                else if (order[j] == "DIV")
                {
                    if (s.size() <= 1)
                    {
                        ans = "ERROR";
                        break;
                    }
                    n1 = s.top();
                    s.pop();
                    n2 = s.top();
                    s.pop();

                    if (n1 == 0)
                    {
                        ans = "ERROR";
                        break;
                    }

                    if ((n1 < 0 && n2 > 0) || (n1 > 0 && n2 < 0))
                    {
                        minus = true;
                    }

                    n1 = abs(n2) / abs(n1);

                    if (minus)
                        n1 = -n1;

                    s.push(n1);
                }
                else if (order[j] == "MOD")
                {
                    if (s.size() <= 1)
                    {
                        ans = "ERROR";
                        break;
                    }
                    n1 = s.top();
                    s.pop();
                    n2 = s.top();
                    s.pop();

                    if (n1 == 0)
                    {
                        ans = "ERROR";
                        break;
                    }

                    if (n2 < 0)
                        minus = true;
                    n1 = abs(n2) % abs(n1);

                    if (n1 > 1000000000 || n1 < -1000000000)
                    {
                        ans = "ERROR";
                        break;
                    }
                    if (minus)
                        n1 = -n1;
                    s.push(n1);
                }
                else
                {
                    s.push(NUM[idx++]);
                }
            }

            if (ans == "ERROR")
            {
                cout << ans << '\n';
                continue;
            }
            if (s.size() != 1)
            {
                cout << "ERROR" << '\n';
                continue;
            }
            else
                cout << s.top() << '\n';
        }
        cout << '\n';
    }

    return 0;
}
