#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int map[25][25];
int n;
bool visited[25][25];
int ans;
int counting[625];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int x,int y)
{
        queue<pair<int,int>> q;
        visited[x][y] = true;
        q.push(make_pair(x,y));
        int obstruct = 1;
        while(!q.empty())
        {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for(int i = 0;i<4;i++)
                {
                        int c = a + dx[i];
                        int d = b + dy[i];
                        if(!visited[c][d] && c>=0 && c<n && d>=0 && d<n && map[c][d] != 0)
                        {
                                visited[c][d] = true;
                                q.push(make_pair(c,d));
                                obstruct++;
                        }
                }
        }
        return obstruct;
}
void sol()
{
        memset(visited,false,sizeof(visited));
        for(int i = 0;i<n;i++)
        {
                for(int j = 0;j<n;j++)
                {
                        if(!visited[i][j] && map[i][j] != 0)
                        {
                                counting[ans] = bfs(i,j);
                                ans++;
                        }
                }
        }
}
int main(int argc, char** argv)
{
        cin>>n;
        string s;
        string temp;
        for(int i = 0;i<n;i++){
                cin>>s;
                for(int j = 0;j<n;j++){
                        temp = s[j];
                        map[i][j] = stoi(temp);
                }
        }

        ans = 0;
        sol();
        sort(counting,counting+ans);
        cout<<ans<<endl;;
        for(int i = 0;i<ans;i++)
                cout<<counting[i]<<endl;

 return 0;
}
