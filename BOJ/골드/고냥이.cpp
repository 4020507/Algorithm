#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int alphabet[26];
int a, b;
int N;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;
    a = b = 0;

    string s;
    cin >> s;

    int len = s.length() - 1;
    int cnt = 1;
    alphabet[s[0] - 'a'] = 1;
    int temp;
    int ans = 1;
    int i;
    while (b < len) {
        b++;
        alphabet[s[b] - 'a']++;
        if (alphabet[s[b] - 'a'] == 1) 
            cnt++;
        
        if (cnt > N) {
            for (i = a; i <= b; i++) {
                alphabet[s[i] - 'a']--;

                if (alphabet[s[i] - 'a'] == 0) {
                    cnt--;
                    a = i + 1;

                    if (a > b)
                        b = a;
                    break;
                }
            }
        }

        ans = ans < (b - a) + 1 ? (b - a) + 1 : ans;
    }

    cout << ans;

    return 0;

}
