#include <iostream>
#include <string.h>
using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV141J8KAIcCFAYD&categoryId=AV141J8KAIcCFAYD&categoryType=CODE
*/
struct node
{
	int left;
	int right;
	char* info = new char(sizeof(100));
};


double Cal(int curr, node tree[])
{
	if (!strcmp(tree[curr].info, "+"))
		return (double)Cal(tree[curr].left - 1, tree) + (double)Cal(tree[curr].right - 1, tree);
	else if (!strcmp(tree[curr].info, "-"))
		return (double)Cal(tree[curr].left - 1, tree) - (double)Cal(tree[curr].right - 1, tree);
	else if (!strcmp(tree[curr].info, "/"))
		return (double)Cal(tree[curr].left - 1, tree) / (double)Cal(tree[curr].right - 1, tree);
	else if (!strcmp(tree[curr].info, "*"))
		return (double)Cal(tree[curr].left - 1, tree) * (double)Cal(tree[curr].right - 1, tree);
	else {

		double re = atof(tree[curr].info);
		return re;
	}
}
int main(void)
{
	int N;
	int node_num;
	string info;
	int subtree1;
	int subtree2;

	for (int test_case = 1;test_case <= 10;test_case++)
	{
		node tree[1000];
		scanf("%d",&N);

		for (int i = 0;i < N;i++)
		{
			cin >> node_num >> info;
			if (info == "-" || info == "+" || info == "*" || info == "/")
			{
				scanf("%d%d", &subtree1, &subtree2);
				//cin >> subtree1 >> subtree2;
				tree[i].left = subtree1;
				tree[i].right = subtree2;
			}
			strcpy(tree[i].info, info.c_str());
		}
		cout << "#" << test_case << " " << Cal(0, tree) << endl;;

	}
}
