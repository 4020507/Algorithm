#include<iostream>
#include<algorithm>

using namespace std;

pair<long long,int> sum[100000];
pair<long long, int> score[100000];
pair<int, int> ranking[100000];

bool scoreSort(pair<long long, int>& a, pair<long long, int>& b){
	return a.first > b.first;
}

bool indexSort(pair<int, int>& a, pair<int, int>& b){
	return a.second < b.second;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int N;

	cin>>N;

	int i,j,k;

	for(i = 0;i<3;i++){
		for(j = 0;j<N;j++){
			cin>>score[j].first;
			sum[j].first += score[j].first;
			sum[j].second = j;
			score[j].second = j;
		}
		sort(score,score+N,scoreSort);

		ranking[0].first = 1;
		ranking[0].second = score[0].second;
		
		for(j = 1;j<N;j++){
			if(score[j].first == score[j-1].first){
				ranking[j].first = ranking[j-1].first;
			}
			else{
				ranking[j].first = j+1;
			}
			ranking[j].second = score[j].second;
		}

		sort(ranking,ranking+N,indexSort);
		for(j = 0;j<N;j++){
			cout<<ranking[j].first<<' ';
		}
		cout<<'\n';
	}

	sort(sum,sum+N,scoreSort);
	ranking[0].first = 1;
	ranking[0].second = sum[0].second;

	for(i = 1;i<N;i++){
		if(sum[i].first == sum[i-1].first){
			ranking[i].first = ranking[i-1].first;
		}
		else{
			ranking[i].first = i+1;
		}
		ranking[i].second = sum[i].second;
	}

	sort(ranking,ranking+N,indexSort);

	for(i = 0;i<N;i++){
		cout<<ranking[i].first<<' ';
	}

	return 0;
}
