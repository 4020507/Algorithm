#include <iostream>
#include <cstring>
using namespace std;

/*
There are N problems.
Each problem can have a different point between 1 to 100
calculate number of cases that a person can earn.


https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn
*/

int point[101];
bool fin_score[10001];

int main(void)
{
	int T;
	int N;
	int max;
	int count;
	scanf("%d", &T);//input number of cases you want to test

	for (int testCase = 1; testCase <= T;testCase++) {
		scanf("%d", &N);//input the number of problems
		memset(point, 0, sizeof(point));
		memset(fin_score, false, sizeof(fin_score));
		max = 0;
		count = 0;

		for (int i = 0;i < N;i++) {
			scanf("%d", &point[i]);
			max += point[i];//cacluate max score
		}
		fin_score[0] = true;//score 0 is always possible for all cases
		for (int j = 0;j < N;j++) {
			for (int k = max;k >= 0;k--) {
				if (fin_score[k]) {//find a number which is true
					fin_score[k + point[j]] = true;
				}
			}
		}

		for (int l = 0;l <= max;l++) {
			if (fin_score[l] == true)
				count++;
		}
		cout << "#" << testCase << " " << count << endl;
	}
}
