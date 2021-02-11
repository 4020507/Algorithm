#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

char name[20000][51];
int idx[20000];

bool cmp(int a,int b)
{
	if (strlen(name[a]) == strlen(name[b]))
		return (strcmp(name[a],name[b]) < 0);
	else
		return strlen(name[a]) < strlen(name[b]);
}
int main(void)
{
	int T;
	cin >> T;
	int N;
	

	for (int test_case = 1;test_case <= T;test_case++)
	{
		scanf("%d", &N);
		
		for (int i = 0;i < N;i++)
		{
			scanf("%s", name[i]);
			idx[i] = i;

		}
		sort(idx,idx+N,cmp);


		cout << "#" << test_case << endl;
		for (int i = 1;i < N;i++)
		{
			if (strcmp(name[idx[i - 1]], name[idx[i]]))
				printf("%s\n", name[idx[i - 1]]);
		}
		if (strcmp(name[idx[N - 1]], name[idx[N-2]]))
			printf("%s\n", name[idx[N-1]]);
	}
	return 0;
}
