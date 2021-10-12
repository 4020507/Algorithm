#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char* argv[]) {
    string s[5];

    for (int i = 0;i < 5;i++)
        cin >> s[i];
    
    string ans = "";

    for (int j = 0;j < 15;j++)
    {
        for (int i = 0;i < 5;i++)
        {
            if (s[i].length() > j)
            {
                ans += s[i][j];
            }
        }
    }
    
    cout << ans;
    return 0;
}
