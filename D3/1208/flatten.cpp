#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
The length of width is 100
Each space has piled boxes.
Input the number of chances to move a box to make the place flat as much as you can.
Output is the difference between the highest and the lowest

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV139KOaABgCFAYh
*/

int main(void)
{
	int change;
	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin>> change;//input chances you can shift one box
		vector<int> box;
		int height;
		for (int i = 0;i < 100;i++) {
			scanf("%d", &height);//input height of the box.For example, 2 means 2 boxes are piled
			box.push_back(height);
		}
		sort(box.begin(), box.end());//sort it in asceding order

		for (int i = 0;i < change;i++)
		{
			if (box[0] != box[99]) {//Move one box from the highest, and put it on the lowest place
				box[0]++;
				box[99]--;
				sort(box.begin(), box.end());
			}
			else
				break;
		}
		cout << "#" << test_case << " " << box[99] - box[0] << endl;
	}
}
