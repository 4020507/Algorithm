#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV141176AIwCFAYD&categoryId=AV141176AIwCFAYD&categoryType=CODE
*/
char tree[200];

int main(void)
{
	int N;

	for (int test_case  = 1;test_case <= 10;test_case++)
	{
		cin >> N;
		int node_num;
		char node_data;
		int next_node1;
		int next_node2;
		for (int i = 0;i < N;i++) {
			if (i * 2 + 2< N)
				cin >> node_num >> node_data >> next_node1 >> next_node2;
			else if (i * 2 + 1< N)
				cin >> node_num >> node_data >> next_node1;
			else
				cin >> node_num >> node_data;
			tree[i] = node_data;
		}
		
		int possible = 1;
		for (int i = 0;i < N;i++)
		{
			if (i * 2 + 1< N) {
				if (tree[i] >= '0' && tree[i] <= '9') {
					possible = 0;
					break;
				}
			}
			else {
				if (tree[i] >= '0' && tree[i] <= '9') {
					continue;
				}
				else {
					possible = 0;
					break;
				}
			}
		}
		cout << "#" << test_case << " " << possible << endl;

	}
}
