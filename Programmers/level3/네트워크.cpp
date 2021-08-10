#include <string>
#include <vector>
#include <set>
using namespace std;

int parent[201];

int findParent(int a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = findParent(parent[a]);
}

void Union(int a, int b,int n)
{
    a = findParent(a);
    b = findParent(b);
    
    if(a == b)
        return;
    if(a<b){
        parent[b] = a;
        
        for(int i = 0;i<n;i++)
        {
            if(parent[i] == b)
                parent[i] = a;
        }
    }
    else{
        parent[a] = b;
        
        for(int i = 0;i<n;i++)
        {
            if(parent[i] == a)
                parent[i] = b;
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0;i<n;i++)
        parent[i] = i;
    
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(computers[i][j] == 1)
            {
                Union(i,j, n);
            }
        }
    }
    
    set<int> s;
    
    for(int i = 0;i<n;i++)
        s.insert(parent[i]);
    
    return s.size();
}
