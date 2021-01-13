#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15FZuqAL4CFAYD
*/
int decode(string s)
{
	if (s == "0001101")
		return 0;
	else if (s == "0011001")
		return 1;
	else if (s == "0010011")
		return 2;
	else if (s == "0111101")
		return 3;
	else if (s == "0100011")
		return 4;
	else if (s == "0110001")
		return 5;
	else if (s == "0101111")
		return 6;
	else if (s == "0111011")
		return 7;
	else if (s == "0110111")
		return 8;
	else
		return 9;
}
int main(void)
{
	int temp[100];
	bool detected = false;
	int T;
	int vertical, horizontal;

	cin >> T;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> vertical >> horizontal;
		detected = false;
		string code = "";
		int count = 0;
		int num[8];

		for (int i = 0;i < vertical;i++) {
			for (int j = 0;j < horizontal;j++) {
				scanf("%1d", &temp[j]);
				if (temp[j] == 1 && detected == false) {
					detected = true;
				}
			}
			if (detected == true && code == "")
				for (int k = horizontal-1;k >= 0;k--) {
					if (temp[k] == 1) {
						for (int l = k;;l--) {
							code += to_string(temp[l]);
							count++;
							if (count == 56)
								break;
						}
						break;
					}
				}
		}
		reverse(code.begin(), code.end());

		count = 0;
		while (count < 8) {
			string a = "";
			for (int i = count * 7;i < count * 7 + 7;i++)
				a += code.at(i);
			num[count] = decode(a);
			count++;
		}
		
		int sum = 0;
		int odd = 0;
		int even = 0;
		for (int i = 0;i < 7;i++) {
			if (i % 2 == 0)
				odd += num[i];
			else
				even += num[i];
		}
		sum = odd * 3 + even + num[7];
		cout << "#" << test_case << " ";
		if (sum % 10 == 0) {
			sum = 0;
			for (int i = 0;i < 8;i++)
				sum += num[i];
			cout << sum << endl;
		}
		else
			cout << 0 << endl;
			
	}

	return 0;
}
