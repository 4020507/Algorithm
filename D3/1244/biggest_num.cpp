#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

/*
input the inital number and chance to the number of change.
find the biggest number
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE
*/
int chance;
int result;
string input;

void dfs(int depth, int a) {
	if (depth == chance) {//if you used all chances to change, check the final number and the previous result
		if (stoi(input) > result) 
			result = stoi(input);
		return;
	}

	for (int i = a; i < input.size()-1; i++) {
		for (int j = i + 1; j < input.size(); j++) {
			//swap each number, and check all possible cases to find the biggest possible number
			swap(input[i], input[j]);
			dfs(depth + 1, i);
			swap(input[i], input[j]);
		}
	}

}



int main() {

	int T;
	cin >> T;//input cases you want to test

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> input;//input format is 'initial_number chance'
		cin >> chance;
		result = 0;

		if (chance > input.size())
			chance = input.size();//if the number of chance to change is bigger than digits, make it equal to the size of digits. 
		dfs(0, 0);

		cout << "#" << test_case << " "<< result << endl;

	}

	return 0;
}
