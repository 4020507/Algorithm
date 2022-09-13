#include <iostream>
#include<string.h>
#include<set>
using namespace std;

int N;
int connected[101];
bool visited[101];
set<int> v;
bool check = false;
void dfs(int start, int end) {

    if (visited[end]) {
        if (start == end) {
            v.insert(start);
            check = true;
        }

        return;
    }
    

    visited[end] = true;
    dfs(start, connected[end]);


    if (check) {
        v.insert(end);
        v.insert(connected[end]);
    }
}
int main(int argc, const char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    memset(visited, false, sizeof(visited));
    memset(connected, 0, sizeof(connected));

    for (int i = 1; i <= N; i++) {
        cin >> connected[i];
    }

    for (int i = 1; i <= N; i++) {
        visited[i] = true;
        dfs(i, connected[i]);
        check = false;
        memset(visited, false, sizeof(visited));
    }

    cout << v.size() << '\n';

    for (auto s : v) {
        cout << s << '\n';
    }
    return 0;
}
