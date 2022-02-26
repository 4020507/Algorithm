#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>N>>M;

	int height,speed;
	vector<int> rule;
	for(int i = 0;i<N;i++)
	{
		cin>>height>>speed;

		for(int j = 0;j<height;j++)
		{
			rule.push_back(speed);
		}
	}

	vector<int> real;
	for(int i = 0;i<M;i++)
	{
		cin>>height>>speed;

		for(int j = 0;j<height;j++)
		{
			real.push_back(speed);
		}
	}
	int diff = 0;

	for(int i = 0;i<=100;i++)
	{
		diff = max(diff,real[i] - rule[i]);
	}
	cout<<diff;
	return 0;
}
