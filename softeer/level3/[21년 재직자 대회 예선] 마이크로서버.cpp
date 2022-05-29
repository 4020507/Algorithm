#include<iostream>
#include<algorithm>

using namespace std;

int N, T;
int memories[100000];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>T;

	int start,end;
	int servers, sum, cnt300;
	for(int test_case = 1;test_case<=T;test_case++){
		cin>>N;

		for(start = 0;start<N;start++){
			cin>>memories[start];
		}
		sort(memories,memories+N);
		start = servers = cnt300 = 0;
		end = N-1;

		while(start <= end && memories[end] > 600){
			servers++;
			end--;
		}
		
		while(start <= end && memories[start] + memories[end] > 900){
			servers++;
			end--;
		}

		while(start < end && memories[start] == 300 && memories[end] == 600){
			servers++;
			start++;
			end--;
		}

		while(start <= end && memories[start] == 300){
			cnt300++;
			start++;
		}

		while(start < end){
			if(memories[start] + memories[end] <= 900){
				servers++;
				start++;
				end--;
			}
			else if(cnt300 > 0){
				servers++;
				end--;
				cnt300--;
			}
			else{
				servers++;
				end--;
			}
		}
		if(start == end) {
			servers++;
			if(cnt300 > 0){
				cnt300--;
			}
		}
		cout<<servers + (cnt300 + 2) / 3<<'\n';
	}
	return 0;
}
