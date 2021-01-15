#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stdio.h>
using namespace std;

/*
find the number of sub matrix.
There is a big matrix which have sub_matrixes
sub_matrixes can be identified by non zero elements.
The format of output is #testnumber number of sub_matrix sub_matrixes' column row
Moreover, a sub matrix that has smaller column x row should be placed in front.
If there is sub matrixes that have the same value of column x row, put the matrix which is smaller column is placed in front

The size of a big matrix is maximum 100 x 100

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18LoAqItcCFAZN

*/
struct sub_matrix {
	int i;
	int j;
	int multi;
};
bool compare(sub_matrix a, sub_matrix b)
{
	if (a.multi == b.multi)
		return a.j < b.j;
	else
		return a.multi < b.multi;
}

int main(void)
{
	int T;
	cin >> T;//input number of cases you want to test

	for (int test_case = 1;test_case <= 10;test_case++)
	{
		int n;
		int matrix[100][100];
		bool visited[100][100] = { false };
		cin >> n;//nxn bit matrix
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				scanf("%d", &matrix[i][j]);

		int column = 0;
		int count1 = 0;
		int count2 = 0;
		int sequence = 0;
		vector<sub_matrix> v;
		bool check = false;
		while (column < n) 
		{
			for (int i = 0;i < n;i++) {
				if (visited[column][i])//if the number is already counted, go to next
					continue;
				visited[column][i] = true;
				if (!check && matrix[column][i] != 0) {
					check = true;
					count1++;//count1 is for the size of row
				}
				else if (check && matrix[column][i] != 0)
					count1++;
				else if (check && matrix[column][i] == 0) {//if this is the end of row, start to count the size of column
					check = false;
					for (int j = column;j < n;j++) {
						if (!check && matrix[j][i-1] != 0) {
							check = true;
							count2++;
						}
						else if (check && matrix[j][i-1] != 0)
							count2++;
						else if (matrix[j][i-1] == 0 && check)
							break;
					}
					v.push_back({ count1, count2, count1 * count2 });
					int L = i - count1;
					int m = L + count1;
					for (int k = column;k < count2 + column;k++) {//make all numbers true to identify that matrix is counted
						for (int l = L;l < m;l++)
							visited[k][l] = true;
					}
					count1 = 0;
					count2 = 0;
					sequence++;//sequence is the number of sub matrixes
					check = false;
				}
			}
			column++;
		}
		sort(v.begin(), v.end(),compare);
		cout << "#" << test_case << " " << sequence << " ";
		for (int i = 0;i < v.size();i++)
			cout << v[i].j << " " << v[i].i << " ";
		cout << endl;
	}

	return 0;
}
