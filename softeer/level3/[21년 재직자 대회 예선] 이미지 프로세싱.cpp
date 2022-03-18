#include<iostream>
#include<string.h>
#include<queue>

using namespace std;
int image[129][129];
int H,W,Q,i,j;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> q;
int x,y,pixel,c,nx,ny;
void bfs()
{
	q.push({x,y});
	image[x][y] = c;

	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(j = 0;j<4;j++)
		{
			nx = x + dx[j];
			ny = y + dy[j];

			if(nx >= 1 && nx <= H && ny >= 1 && ny <= W)
			{
				if(image[nx][ny] == pixel)
				{
					image[nx][ny] = c;
					q.push({nx,ny});
				}
			}
		}
	}

}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>H>>W;

	for(i = 1;i<=H;i++)
	{
		for(j = 1;j<=W;j++)
		{
			cin>>image[i][j];
		}
	}

	cin>>Q;
	

	for(i = 0;i<Q;i++)
	{
		cin>>x>>y>>c;
		pixel = image[x][y];

		if(pixel != c)
			bfs();
	}

	for(i = 1;i<=H;i++)
	{
		for(j = 1;j<=W;j++)
		{
			cout<<image[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
