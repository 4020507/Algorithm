#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N,M;
char alphabet[2000][2000];
bool visited[2000][2000];
string ans;
int dx[2] = {0,1};
int dy[2] = {1,0};

int main(void)
{
    int T;
    cin>>T;
    string temp;
    int size,a,b,c,d;
    char min;
    bool flag;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>M;
        
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            	cin>>alphabet[i][j];
        }

        memset(visited,false,sizeof(visited));
        ans = alphabet[0][0];
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        visited[0][0] = true;
        flag= false;
        while(!q.empty())
        {
            size = q.size();
            min = 'z';
            vector<pair<int,int>> v;
            
            for(int i = 0;i<size;i++)
            {
                a = q.front().first;
                b = q.front().second;
                
                q.pop();
                
                if(a == N-1 && b == M-1)
                {
                    flag= true;
                    break;
                }
                
                for(int i = 0;i<2;i++)
                {
                    c = a + dx[i];
                    d = b + dy[i];
                    
                    if(c<N && d<M)
                    {
                        if(!visited[c][d])
                        {
                            if(alphabet[c][d] <= min)
                            {
                                if(alphabet[c][d] < min)
                                	v.clear();
                            visited[c][d] = true;
                            v.push_back(make_pair(c,d));
                            min = alphabet[c][d];
                            }
                        }
                    }
                }
            }
            size = v.size();
            for(int i = 0;i<size;i++)
                q.push(v[i]);
            if(!flag)
            {
                ans += min;
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
