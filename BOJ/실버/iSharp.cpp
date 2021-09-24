#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int main(int argc, char** argv)
{
	string s;

	getline(cin, s);

	string basic;

	int start = 0;

	while (s[start] != ' ')
	{
		start++;
	}
	basic = s.substr(0, start);

	string name = "";
	string additional;
	start++;
	int end = start;
	bool n = false;

	while (true)
	{
		if ((s[end] != '[' && s[end] != '*' && s[end] != '&' && s[end] != ',' && s[end] != ';') && !n)
		{
			end++;
			continue;
		}
		else if (!n && name == "")
		{
			name = s.substr(start, end - start);
			start = end;
			n = true;
			continue;
		}
		else if (s[end] != ',' && s[end] != ';')
		{
			end++;
		}
		else if(s[end] == ',' || s[end] == ';')
		{
			additional = s.substr(start, end - start);
			reverse(additional.begin(), additional.end());

			int len = additional.size();
			int beg = 0;

			while (beg < len)
			{
				if (additional[beg] == ']')
				{
					additional[beg++] = '[';
					additional[beg] = ']';
				}
				beg++;
			}
			if(s[end] == ',')
				cout << basic << additional << ' ' << name << ';' << '\n';
			
			if (s[end] == ';') {
				cout << basic << additional << ' ' << name << ';';
				break;
			}
			
			n = false;
			name = "";
			additional = "";
			end += 2;
			start = end;
		}
	}

	return 0;
}
