#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    
    int N;
    cin >> N;

    int startM, startD, endM, endD;
    int converted1, converted2;

    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++) {
        cin >> startM >> startD >> endM >> endD;

        if (startM < 3) {
            converted1 = 301;
        }
        else {
            converted1 = startM * 100 + startD;
        }

        if (endM > 11) {
            converted2 = 1201;
        }
        else {
            converted2 = endM * 100 + endD;
        }

        v.push_back({ converted1,converted2 });
    }

    sort(v.begin(), v.end());

    converted1 = 300;
    converted2 = 301;
    int last = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (v[i].first > converted1 && v[i].first <= converted2) {
            if (last < v[i].second) {
                last = v[i].second;
            }
            if (v[i].second == 1201) {
                cnt++;
                converted2 = 1201;
                break;
            }
        }
        else {
            if (converted2 >= last) {
                break;
            }
            cnt++;
            converted1 = converted2;
            converted2 = last;
            i--;
        }
    }

    if (converted2 == 1201)
        cout << cnt;
    else
        cout << 0;
    return 0;

}
