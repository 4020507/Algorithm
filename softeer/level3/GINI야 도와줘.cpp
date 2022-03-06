#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
char map[50][50];
bool visited[50][50];
int rain[50][50];
pair<int,int> departure;
pair<int,int> arrival;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int R,C;
int main(int argc, char** argv)
{
	cin>>R>>C;
	memset(rain,0,sizeof(rain));
	memset(visited,false,sizeof(visited));
	for(int i = 0;i<R;i++)
	{
		for(int j = 0;j<C;j++)
		{
			cin>>map[i][j];

			if(map[i][j] == 'W') departure = {i,j};
			if(map[i][j] == 'H') arrival = {i,j};
		}
	}
	
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{departure.first,departure.second}});
	visited[departure.first][departure.second] = true;
	int x,y,nx,ny,t,size;
	while(!q.empty())
	{
		t = q.front().first;

		for(int i = 0;i<R;i++)
		{
			for(int j = 0;j<C;j++)
			{
				if(map[i][j] == '*' && rain[i][j] <= t)
				{
					for(int k = 0;k<4;k++)
					{
						nx = i + dx[k];
						ny = j + dy[k];

						if(nx>=0 && nx<R && ny>=0 && ny<C)
						{
							if(map[nx][ny] != 'X' && map[nx][ny] != '*' && map[nx][ny] != 'H')
							{
								map[nx][ny] = '*';
								rain[nx][ny] = t+1;
							}
						}
					}
				}
			}
		}


		size = q.size();

		while(size > 0)
		{
			x = q.front().second.first;
			y = q.front().second.second;
			size--;
			q.pop();
			if(x == arrival.first && y == arrival.second)
			{
				cout<<t;
				return 0;
			}
			for(int k = 0;k<4;k++)
			{
				nx = x + dx[k];
				ny = y + dy[k];

				if(nx >= 0 && nx < R && ny >= 0 && ny < C)
				{
					if(!visited[nx][ny] && map[nx][ny] != '*' && map[nx][ny] != 'X')
					{
						q.push({t+1,{nx,ny}});
						visited[nx][ny] = true;
					}
				}
			}
		}

	}

	cout<<"FAIL";
	return 0;
}
