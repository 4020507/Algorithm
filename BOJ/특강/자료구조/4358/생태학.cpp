#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;


int main(void)
{
    map<string, double> m;

    string s;
    double cnt = 0;
    
    while (getline(cin, s))
    {
        m[s]++;
        cnt++;
    }

    cout << fixed;
    cout.precision(4);
    for (auto t : m)
    {
        cout << t.first << ' ' << 100 * t.second / cnt << '\n';
    }
    return 0;

}

