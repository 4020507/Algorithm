#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, K;
vector<int> v;
bool visited[100001];
int parent[100001];

int main(int argc, const char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    queue<int> q;
    q.push(N);
    memset(visited, false, sizeof(visited));
    visited[N] = true;
    //parent[N] = N;

    int curr;

    while (!q.empty()) {
        curr = q.front();

        q.pop();

        if (curr == K) {
            int idx = K;
            while (idx != N) {
                v.push_back(idx);
                idx = parent[idx];
                
            }
            break;
        }
        if (curr - 1 >= 0) {
            if (!visited[curr - 1]) {
                parent[curr - 1] = curr;
                visited[curr - 1] = true;
                q.push(curr - 1);
            }
        }

        if (curr + 1 <= 100000) {
            if (!visited[curr + 1]) {
                parent[curr + 1] = curr;
                visited[curr + 1] = true;
                q.push(curr + 1);
            }
        }

        if (curr * 2 <= 100000) {
            if (!visited[curr * 2]) {
                parent[curr * 2] = curr;
                visited[curr * 2] = true;
                q.push(curr * 2);
            }
        }
    }

    cout << v.size() << '\n';
    cout << N << ' ';
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    return 0;
}
