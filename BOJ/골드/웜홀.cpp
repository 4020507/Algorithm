#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Edge {

public:
    int s;
    int e;
    int t;

    Edge(int s, int e, int t) {
        this->s = s;
        this->e = e;
        this->t = t;
    }
};
int N, M, W;
int dist[501];
vector<Edge> v;


bool BellmanFord() {
    dist[1] = 0;
    int size = v.size();
    int s, e, t;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < size; j++) {
            s = v[j].s;
            e = v[j].e;
            t = v[j].t;

            if (dist[e] > dist[s] + t) {
                if (i != N)
                    dist[e] = dist[s] + t;
                else
                    return true;
            }
        }
    }

    return false;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    int s, e, t;

    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N >> M >> W;

        for (int i = 1; i <= N; i++)
            dist[i] = 1e9;

        v.clear();

        for (int i = 0; i < M; i++) {
            cin >> s >> e >> t;

            v.push_back(Edge(s,e,t));
            v.push_back(Edge(e, s, t));
        }

        for (int i = 0; i < W; i++) {
            cin >> s >> e >> t;

            v.push_back(Edge(s, e, -t));
        }

        if (BellmanFord())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    
    return 0;

}
