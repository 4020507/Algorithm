#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWNcJ2sapZMDFAV8
*/
int main(void)
{
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	int N;

	int start;
	int end;
	int count;
	int room[200];
	for (int test_case = 1;test_case <= T;test_case++)
	{
		scanf("%d", &N);
		memset(room, 0, sizeof(room));
		count = 0;
		while (count < N) {
			cin >> start >> end;
			if (start > end) {
				int temp = start;
				start = end;
				end = temp;
			}
			
			if (start & 1) start++;
			start /= 2;

			if (end & 1)end++;
			end /= 2;

			for (int i = start - 1;i <= end - 1;i++)
				room[i] += 1;

			count++;
		}
		int answer = 0;
		
		sort(room, room + 200);
		cout << "#" << test_case << " " << room[199] << endl;
	}
}
