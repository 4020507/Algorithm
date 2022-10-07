#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n, t;
vector<string>telephone;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    int i, j;
    string tele;
    bool flag;

    for (i = 0; i < t; i++) {
        cin >> n;

        telephone.clear();

        for (j = 0; j < n; j++) {
            cin >> tele;

            telephone.push_back(tele);
        }

        sort(telephone.begin(), telephone.end());
        flag = true;

        for (j = 0; j < telephone.size() - 1; j++) {

            if (telephone[j].length() > telephone[j+1].length())
                continue;

            if (telephone[j] == telephone[j + 1].substr(0, telephone[j].length())) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
