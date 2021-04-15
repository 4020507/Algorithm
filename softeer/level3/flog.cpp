#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(int argc, char** argv)
{
        int N,M;
        cin>>N>>M;

        vector<pair<int,int>> v;
        int weight[100000];
        bool visited[100000];
        memset(visited,false,sizeof(visited));
        for(int i = 0;i<N;i++)
                cin>>weight[i];
        
        int a,b;

        int count = 0;
        for(int i = 0;i<M;i++)
        {
                cin>>a>>b;
                if(weight[a-1] <= weight[b-1] && !visited[a-1])
                {
                        visited[a-1] = true;
                        count++;
                }
                if(weight[b-1] <= weight[a-1] && !visited[b-1])
                {
                        visited[b-1] = true;
                        count++;
                }
        }
        
        cout<<N - count;
        return 0;
}
