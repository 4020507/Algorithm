#include <string>
#include <vector>

using namespace std;

int graph[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 1;i<=n;i++)
    {
        fill(graph[i],graph[i] + n + 1,1e9);
    }
    
    for(int i = 1;i<=n;i++)
        graph[i][i] = 1;
    
    for(auto r: results)
    {
        graph[r[0]][r[1]] = 1;
    }
    
    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for(int i = 1;i<=n;i++)
    {
        bool possible = true;
        for(int j = 1;j<=n;j++)
        {
            if(graph[i][j] == 1e9 && graph[j][i] == 1e9)
            {
                possible = false;
                break;
            }
        }
        
        if(possible)
            answer++;
    }
    return answer;
}
