#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int seats[22][22]; //0: 빈 좌석
int IDs[10001];//0: 자리에 앉지 못함 1: 식사 완료 2: 식사 중
int IDseat[10001][2];
int N,M;

int nearest(int x, int y){
	int minD = 1e9;

	int i,j,d;

	for(i = 1;i<=N;i++){
		for(j = 1;j<=M;j++){
			if(seats[i][j] != 0){
				d = (x-i) * (x-i) + (y-j) * (y-j);

				if(d < minD){
					minD = d;
				}
			}
		}
	}

	return minD;
}
bool AssignSeat(int id){

	int i,j,d;
	int maxD = 0;

	for(i = 1;i <= N;i++){
		for(j = 1;j <= M;j++){
			if(seats[i][j] == 0 && seats[i-1][j] == 0 && seats[i+1][j] == 0
			&& seats[i][j-1] == 0 && seats[i][j+1] == 0
			){
				d = nearest(i,j);

				if(d > maxD){
					maxD = d;
					IDseat[id][0] = i;
					IDseat[id][1] = j;
				}
			}
		}
	}

	if(maxD == 0){
		return false;
	}

	seats[IDseat[id][0]][IDseat[id][1]] = 1;
	IDs[id] = 2;

	return true;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int Q;

	cin>>N>>M>>Q;

	string action;
	int id,i,j;

	memset(seats,0,sizeof(seats));
	memset(IDs,0,sizeof(IDs));

	for(int q = 0; q < Q; q++){
		cin>>action>>id;

		if(action == "In"){
			if(IDs[id] == 0){
				if(AssignSeat(id)){
					cout<<id<<" gets the seat "<<'('<<IDseat[id][0]<<", "<<IDseat[id][1]<<")."<<'\n';
				}
				else{
					cout<<"There are no more seats."<<'\n';
				}
			}
			else if(IDs[id] == 1){
				cout<<id<<" already ate lunch."<<'\n';
			}
			else{
				cout<<id<<" already seated."<<'\n';
			}
		}
		else{
			if(IDs[id] == 0){
				cout<<id<<" didn't eat lunch."<<'\n';
			}
			else if(IDs[id] == 1){
				cout<<id<<" already left seat."<<'\n';
			}
			else{
				cout<<id<<" leaves from the seat ("<<IDseat[id][0]<<", "<<IDseat[id][1]<<")."<<'\n';
				IDs[id] = 1;
				seats[IDseat[id][0]][IDseat[id][1]] = 0;
			}
		}
	}
	return 0;
}
