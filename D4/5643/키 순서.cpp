#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<int> taller[501];
vector<int> smaller[501];
bool visited[501];
int cnt[501];

void tallDfs(int p, int curr){
	for(int i = 0;i<taller[curr].size();i++){
    	if(!visited[taller[curr][i]]){
        	visited[taller[curr][i]] = true;
            cnt[p]++;
            tallDfs(p,taller[curr][i]);
        }
    }
}

void smallDfs(int p, int curr){
	for(int i = 0;i<smaller[curr].size();i++){
    	if(!visited[smaller[curr][i]]){
        	visited[smaller[curr][i]] = true;
            cnt[p]++;
            smallDfs(p,smaller[curr][i]);
        }
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
    
	cin>>T;
    
    int a,b,N,M,i;
    int ans;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N>>M;
        ans = 0;
        for(i = 1;i<=N;i++){
        	taller[i].clear();
            smaller[i].clear();
            cnt[i] = 1;
        }
        
        for(i = 0;i<M;i++){
        	cin>>a>>b;
            taller[a].push_back(b);
            smaller[b].push_back(a);
        }
        
        for(i = 1;i<=N;i++){
        	memset(visited,false,sizeof(visited));
            tallDfs(i,i);
            smallDfs(i,i);
            
            if(cnt[i] == N){
            	ans++;
            }
        }
        
        cout<<'#'<<test_case<<' '<<ans<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
