#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

unsigned long long computers[100000];

int main(int argc, char** argv)
{
	int N;
	unsigned long long budget;
	

	cin>>N>>budget;

	int i;

	for(i = 0;i<N;i++){
		cin>>computers[i];
	}

	unsigned long long left = 1;
	unsigned long long mid;
	unsigned long long right = 2000000000;

	unsigned long long ans = 0;
	unsigned long long cost;

	while(left <= right){
		mid = (left+right)/2;
		cost = 0;

		for(i = 0;i<N;i++){
			if(computers[i] < mid){
				cost += (mid-computers[i]) * (mid-computers[i]);

				if(cost > budget){
					break;
				}
			}
		}
		//cout<<cost<<' '<<mid<<endl;

		if(cost <= budget){
				ans = max(ans,mid);
				left = mid+1;
			}
		else{
			right = mid -1;
		}
	}

	cout<<ans;

	r
