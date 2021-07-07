#pragma warning(disable:4996)
#include<iostream>
#include<string.h>
#define INF 1e9

using namespace std;


int main(void) {
    
    int N, M;
    //노드 수, 간선 수
    cin >> N >> M;

    int graph[501][501];
    
    for (int i = 0; i < 501; i++) {
        fill(graph[i], graph[i] + 501, INF);
    }

    for (int a = 1; a <= N; a++) {
        graph[a][a] = 0;
        
    }
    for (int i = 0;i < M;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a][b] = c;
    }

    for (int i = 1;i <= M;i++)
    {
        for (int a = 1;a <= M;a++)
        {
            for (int b = 1;b <= M;b++)
            {
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
            }
        }
    }

    for (int a = 1;a <= N;a++)
    {
        for (int b = 1;b <= N;b++)
        {
            if (graph[a][b] == INF)
            {
                cout << "INFINITY" << " ";
            }
            else
            {
                cout << graph[a][b] << " ";
            }
        }
        cout << endl;
    }
    
}
