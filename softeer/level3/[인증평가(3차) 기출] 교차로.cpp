#include<iostream>
#include<queue>

using namespace std;

int ans[200000];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int N;

	queue<pair<int,int>> A;
	queue<pair<int,int>> B;
	queue<pair<int,int>> C;
	queue<pair<int,int>> D;

	cin>>N;

	int i;
	int t;
	char road;

	for(i = 0;i<N;i++){
		cin>>t>>road;
		ans[i] = -1;

		if(road == 'A'){
			A.push({i,t});
		}
		else if(road == 'B'){
			B.push({i,t});
		}
		else if(road == 'C'){
			C.push({i,t});
		}
		else{
			D.push({i,t});
		}
	}

	int a,b,c,d;
	int curr = 0;
	bool passA, passB, passC, passD;
	bool stuckA, stuckB, stuckC, stuckD;

	while(!A.empty() || !B.empty() || !C.empty() || !D.empty()){
		a = 1e10;
		b = 1e10;
		c = 1e10;
		d = 1e10;

		if(!A.empty()){
			a = A.front().second;
		}
		
		if(!B.empty()){
			b = B.front().second;
		}

		if(!C.empty()){
			c = C.front().second;
		}

		if(!D.empty()){
			d = D.front().second;
		}

		if(curr < a && curr < b && curr < c && curr < d){
			curr = min(a,min(b,min(c,d)));
		}

		passA = passB = passC = passD = stuckA = stuckB = stuckC = stuckD = false;

		if(!A.empty()){
			if(a <= curr && d > curr){
				passA = true;
			}

			if(!passA && a <= curr){
				stuckA = true;
			}
		}

		if(!B.empty()){
			if(b <= curr && a > curr){
				passB = true;
			}

			if(!passB && b <= curr){
				stuckB = true;
			}
		}

		if(!C.empty()){
			if(c <= curr && b > curr){
				passC = true;
			}

			if(!passC && c <= curr){
				stuckC = true;
			}
		}

		if(!D.empty()){
			if(d <= curr && c > curr){
				passD = true;
			}

			if(!passD && d <= curr){
				stuckD = true;
			}
		}

		if(stuckA && stuckB && stuckC && stuckD){
			break;
		}

		if(passA){
			ans[A.front().first] = curr;
			A.pop();
		}

		if(passB){
			ans[B.front().first] = curr;
			B.pop();
		}

		if(passC){
			ans[C.front().first] = curr;
			C.pop();
		}

		if(passD){
			ans[D.front().first] = curr;
			D.pop();
		}

		curr++;
	}

	for(i = 0;i<N;i++){
		cout<<ans[i]<<'\n';
	}

	return 0;
}
