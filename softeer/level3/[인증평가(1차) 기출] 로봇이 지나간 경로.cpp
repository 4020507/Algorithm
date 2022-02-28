#include<iostream>
#include<string.h>
#include<vector>
#include<string>
using namespace std;
int H, W;
char matrix[25][25];
bool visited[25][25];
vector<pair<int,int>> trace;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
pair<int,int> start;
int dir;
string order;

void backtracking(pair<int,int> s, int d, string o, int x, int y, int cnt, int next)
{
	if(cnt == trace.size())
	{
		if(order.size() > o.size() || order.size() == 0)
		{
			order = o;
			start = s;
			dir = d;
		}
		return;
	}

	int nx1,ny1,nx2,ny2;
	int nd;
	string c;
	for(int i = 0;i<4;i++)
	{
		nd = (next+i)%4;
		nx1 = x + dx[nd];
		ny1 = y + dy[nd];
		nx2 = x + dx[nd] * 2;
		ny2 = y + dy[nd] * 2;
		
		if(nx2 >= 0 && nx2 < H && ny2 >= 0 && ny2 < W)
		{
			if(!visited[nx2][ny2] && !visited[nx1][ny1] && matrix[nx1][ny1] == '#' && matrix[nx2][ny2] == '#')
			{
				if(i == 0) c = "A";
				if(i == 1) c = "LA";
				if(i == 2) c = "LLA";
				if(i == 3) c = "RA";
				visited[nx1][ny1] = true;
				visited[nx2][ny2] = true;
				backtracking(s,d,o+c,nx2,ny2,cnt+2,nd);
				visited[nx1][ny1] = false;
				visited[nx2][ny2] = false;
			}
		}
	}
}
int main(int argc, char** argv)
{
	cin>>H>>W;

	for(int i = 0;i<H;i++)
	{
		for(int j = 0;j<W;j++){
			cin>>matrix[i][j];
			if(matrix[i][j] == '#')
				trace.push_back({i,j});
		}
	}

	for(auto t:trace)
	{
		pair<int,int> s;
		s.first = t.first;
		s.second = t.second;
		memset(visited,false,sizeof(visited));
		visited[s.first][s.second] = true;
		for(int i = 0;i<4;i++)
		{
			backtracking(s,i,"",t.first,t.second,1,i);
		}
	}

	cout<<start.first + 1<<' '<<start.second + 1<<endl;
	if(dir == 0) cout<<'v'<<endl;
	if(dir == 1) cout<<'>'<<endl;
	if(dir == 2) cout<<'^'<<endl;
	if(dir == 3) cout<<'<'<<endl;
	cout<<order;
	return 0;
}
