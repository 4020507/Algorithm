#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parent[101];
bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int findParent(int a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = findParent(parent[a]);
}

void Union(int a, int b)
{
    a = parent[a];
    b = parent[b];
    
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0;i<n;i++)
        parent[i] = i;
    sort(costs.begin(),costs.end(),cmp);
    
    for(int i = 0;i<costs.size();i++)
    {
        int a = costs[i][0];
        int b = costs[i][1];
        
        if(findParent(a) != findParent(b))
        {
            Union(a,b);
            answer += costs[i][2];
        }
    }
    return answer;
}
