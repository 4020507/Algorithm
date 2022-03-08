#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K,ans;
vector<pair<int,int>> points[21];

void dfs(int cnt, int maxX, int maxY, int minX, int minY)
{
	if(cnt > K)
	{
		ans = min(ans,(maxX-minX) * (maxY-minY));
		return;
	}

	int x,y,area;
	int maxX2,maxY2,minX2,minY2;
	for(int i = 0;i<points[cnt].size();i++)
	{
		x = points[cnt][i].first;
		y = points[cnt][i].second;
		maxX2 = maxX, maxY2 = maxY, minX2 = minX, minY2 = minY;
		if(maxX < x) maxX2 = x;
		if(minX > x) minX2 = x;
		if(maxY < y) maxY2 = y;
		if(minY > y) minY2 = y;

		area = (maxX2 - minX2) * (maxY2 - minY2);
		if(ans <= area)
			continue;

		dfs(cnt+1,maxX2,maxY2,minX2,minY2);
	}
}
int main(int argc, char** argv)
{
	cin>>N>>K;
	int x,y,color;
	for(int i = 0;i<N;i++)
	{
		cin>>x>>y>>color;
		points[color].push_back({x,y});
	}
	ans = 1e9;
	dfs(1,-1e9,-1e9,1e9,1e9);
	cout<<ans;
	return 0;
}
