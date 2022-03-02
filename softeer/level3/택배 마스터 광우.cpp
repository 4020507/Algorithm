#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N,M,K;
	cin>>N>>M>>K;

	int weights[10];

	for(int i = 0;i<N;i++){
		cin>>weights[i];
	}
	int ans = 1e9;
	sort(weights,weights+N);
	do{
		int idx = 0;
		int W;
		int total = 0;
		for(int i = 0;i<K;i++){
			W = 0;
			while(W <= M){
				W += weights[idx++];

				idx %= N;
			}
			idx--;if(idx == -1) idx = N-1;
			W -= weights[idx];
			total += W;
			
		}

		ans = min(total,ans);
	}while(next_permutation(weights,weights+N));

	cout<<ans;
	return 0;
}
