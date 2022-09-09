#include <iostream>
#include<stack>
using namespace std;



int main(int argc, const char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<pair<int, int>> s;
    int N;

    cin >> N;

    int num;

    for (int i = 1; i <= N; i++) {
        cin >> num;

        while (!s.empty()) {
            if (num > s.top().first) {
                s.pop();
            }
            else {
                cout << s.top().second << ' ';
                break;
            }
        }

        if (s.empty()) {
            cout << 0 << ' ';
        }

        s.push({ num,i });
    }

    return 0;
}
