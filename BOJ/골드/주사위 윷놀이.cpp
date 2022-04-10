#include<iostream>
#include<string.h>

using namespace std;

int turns[10];
int scoreList[33] = {
	0,2,4,6,8,10,12,14,16,18,20,
	22,24,26,28,30,32,34,36,38,13,
	16,19,22,24,28,27,26,25,30,35,40,0
};
int mal[4] = { 0, };
int ans = 0;

void dfs(int turn, int score) {
	if (turn == 10) {
		if (ans < score)
			ans = score;
		return;
	}
	int curr, j;
	bool check = true;
	for (int i = 0;i < 4;i++) {
		if (mal[i] >= 32)
			continue;

		curr = mal[i];
		check = true;
		
		if (curr == 5) {
			if (turns[turn] == 1) {
				mal[i] = 20;
			}
			else if (turns[turn] == 2) {
				mal[i] = 21;
			}
			else if (turns[turn] == 3) {
				mal[i] = 22;
			}
			else if (turns[turn] == 4) {
				mal[i] = 28;
			}
			else if (turns[turn] == 5)
				mal[i] = 29;
		}
		else if (curr == 10) {
			if (turns[turn] == 1) {
				mal[i] = 23;
			}
			else if (turns[turn] == 2) {
				mal[i] = 24;
			}
			else if (turns[turn] == 3) {
				mal[i] = 28;
			}
			else if (turns[turn] == 4) {
				mal[i] = 29;
			}
			else if (turns[turn] == 5)
				mal[i] = 30;
		}
		else if (curr == 15) {
			if (turns[turn] == 1) {
				mal[i] = 25;
			}
			else if (turns[turn] == 2) {
				mal[i] = 26;
			}
			else if (turns[turn] == 3) {
				mal[i] = 27;
			}
			else if (turns[turn] == 4) {
				mal[i] = 28;
			}
			else if (turns[turn] == 5)
				mal[i] = 29;
		}
		else if (curr == 20 && turns[turn] >= 3) {
			if (turns[turn] == 3)
				mal[i] = 28;
			else if (turns[turn] == 4)
				mal[i] = 29;
			else if (turns[turn] == 5)
				mal[i] = 30;
		}
		else if (curr == 21 && turns[turn] >= 2) {
			if (turns[turn] == 2)
				mal[i] = 28;
			else if (turns[turn] == 3)
				mal[i] = 29;
			else if (turns[turn] == 4)
				mal[i] = 30;
			else if (turns[turn] == 5)
				mal[i] = 31;
		}
		else if (curr == 22 && turns[turn] >= 1) {
			if (turns[turn] == 1)
				mal[i] = 28;
			else if (turns[turn] == 2)
				mal[i] = 29;
			else if (turns[turn] == 3)
				mal[i] = 30;
			else if (turns[turn] == 4)
				mal[i] = 31;
			else if (turns[turn] == 5)
				mal[i] = 32;
		}
		else if (curr == 23 && turns[turn] >= 2) {
			if (turns[turn] == 2)
				mal[i] = 28;
			else if (turns[turn] == 3)
				mal[i] = 29;
			else if (turns[turn] == 4)
				mal[i] = 30;
			else if (turns[turn] == 5)
				mal[i] = 31;
		}
		else if (curr == 24 && turns[turn] >= 1) {
			if (turns[turn] == 1)
				mal[i] = 28;
			else if (turns[turn] == 2)
				mal[i] = 29;
			else if (turns[turn] == 3)
				mal[i] = 30;
			else if (turns[turn] == 4)
				mal[i] = 31;
			else if (turns[turn] == 5)
				mal[i] = 32;
		}
		else if (curr == 16 && turns[turn] >= 4) {
			if (turns[turn] == 4)
				mal[i] = 31;
			else if (turns[turn] == 5)
				mal[i] = 32;
		}
		else if (curr == 17 && turns[turn] >= 3) {
			if (turns[turn] == 3)
				mal[i] = 31;
			else
				mal[i] = 32;
		}
		else if (curr == 18 && turns[turn] >= 2) {
			if (turns[turn] == 2)
				mal[i] = 31;
			else
				mal[i] = 32;
		}
		else if (curr == 19 && turns[turn] >= 1) {
			if (turns[turn] == 1)
				mal[i] = 31;
			else
				mal[i] = 32;
		}
		else {
			mal[i] += turns[turn];
		}

		for (j = 0;j < 4;j++) {
			if (i == j)
				continue;
			if (mal[i] == mal[j]) {
				check = false;
				break;
			}
		}

		if (!check) {
			mal[i] = curr;
			continue;
		}
		else {
			if (mal[i] >= 32)
				mal[i] = 32;
			dfs(turn + 1, score + scoreList[mal[i]]);
			mal[i] = curr;
		}
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	for (int i = 0;i < 10;i++)
		cin >> turns[i];

	dfs(0, 0);

	cout << ans;

	return 0;
}
