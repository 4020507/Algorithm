#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int digits[5][7];

int none(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 1)
	{
		digits[digit][0] = 0;
		changed++;
	}
	if(digits[digit][1] == 1)
	{
		digits[digit][1] = 0;
		changed++;
	}
	if(digits[digit][2] == 1)
	{
		digits[digit][2] = 0;
		changed++;
	}
	if(digits[digit][3] == 1)
	{
		digits[digit][3] = 0;
		changed++;
	}
	if(digits[digit][4] == 1)
	{
		digits[digit][4] = 0;
		changed++;
	}
	if(digits[digit][5] == 1)
	{
		digits[digit][5] = 0;
		changed++;
	}
	if(digits[digit][6] == 1)
	{
		digits[digit][6] = 0;
		changed++;
	}
	return changed;
}
int zero(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 0)
	{
		digits[digit][0] = 1;
		changed++;
	}
	if(digits[digit][1] == 0)
	{
		digits[digit][1] = 1;
		changed++;
	}
	if(digits[digit][2] == 0)
	{
		digits[digit][2] = 1;
		changed++;
	}
	if(digits[digit][3] == 1)
	{
		digits[digit][3] = 0;
		changed++;
	}
	if(digits[digit][4] == 0)
	{
		digits[digit][4] = 1;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 0)
	{
		digits[digit][6] = 1;
		changed++;
	}
	return changed;
}

int one(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 1)
	{
		digits[digit][0] = 0;
		changed++;
	}
	if(digits[digit][1] == 1)
	{
		digits[digit][1] = 0;
		changed++;
	}
	if(digits[digit][2] == 0)
	{
		digits[digit][2] = 1;
		changed++;
	}
	if(digits[digit][3] == 1)
	{
		digits[digit][3] = 0;
		changed++;
	}
	if(digits[digit][4] == 1)
	{
		digits[digit][4] = 0;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 1)
	{
		digits[digit][6] = 0;
		changed++;
	}
	return changed;
}

int two(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 0)
	{
		digits[digit][0] = 1;
		changed++;
	}
	if(digits[digit][1] == 1)
	{
		digits[digit][1] = 0;
		changed++;
	}
	if(digits[digit][2] == 0)
	{
		digits[digit][2] = 1;
		changed++;
	}
	if(digits[digit][3] == 0)
	{
		digits[digit][3] = 1;
		changed++;
	}
	if(digits[digit][4] == 0)
	{
		digits[digit][4] = 1;
		changed++;
	}
	if(digits[digit][5] == 1)
	{
		digits[digit][5] = 0;
		changed++;
	}
	if(digits[digit][6] == 0)
	{
		digits[digit][6] = 1;
		changed++;
	}
	return changed;
}

int three(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 0)
	{
		digits[digit][0] = 1;
		changed++;
	}
	if(digits[digit][1] == 1)
	{
		digits[digit][1] = 0;
		changed++;
	}
	if(digits[digit][2] == 0)
	{
		digits[digit][2] = 1;
		changed++;
	}
	if(digits[digit][3] == 0)
	{
		digits[digit][3] = 1;
		changed++;
	}
	if(digits[digit][4] == 1)
	{
		digits[digit][4] = 0;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 0)
	{
		digits[digit][6] = 1;
		changed++;
	}
	return changed;
}

int four(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 1)
	{
		digits[digit][0] = 0;
		changed++;
	}
	if(digits[digit][1] == 0)
	{
		digits[digit][1] = 1;
		changed++;
	}
	if(digits[digit][2] == 0)
	{
		digits[digit][2] = 1;
		changed++;
	}
	if(digits[digit][3] == 0)
	{
		digits[digit][3] = 1;
		changed++;
	}
	if(digits[digit][4] == 1)
	{
		digits[digit][4] = 0;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 1)
	{
		digits[digit][6] = 0;
		changed++;
	}
	return changed;
}

int five(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 0)
	{
		digits[digit][0] = 1;
		changed++;
	}
	if(digits[digit][1] == 0)
	{
		digits[digit][1] = 1;
		changed++;
	}
	if(digits[digit][2] == 1)
	{
		digits[digit][2] = 0;
		changed++;
	}
	if(digits[digit][3] == 0)
	{
		digits[digit][3] = 1;
		changed++;
	}
	if(digits[digit][4] == 1)
	{
		digits[digit][4] = 0;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 0)
	{
		digits[digit][6] = 1;
		changed++;
	}
	return changed;
}

int six(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 0)
	{
		digits[digit][0] = 1;
		changed++;
	}
	if(digits[digit][1] == 0)
	{
		digits[digit][1] = 1;
		changed++;
	}
	if(digits[digit][2] == 1)
	{
		digits[digit][2] = 0;
		changed++;
	}
	if(digits[digit][3] == 0)
	{
		digits[digit][3] = 1;
		changed++;
	}
	if(digits[digit][4] == 0)
	{
		digits[digit][4] = 1;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 0)
	{
		digits[digit][6] = 1;
		changed++;
	}
	return changed;
}

int seven(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 0)
	{
		digits[digit][0] = 1;
		changed++;
	}
	if(digits[digit][1] == 0)
	{
		digits[digit][1] = 1;
		changed++;
	}
	if(digits[digit][2] == 0)
	{
		digits[digit][2] = 1;
		changed++;
	}
	if(digits[digit][3] == 1)
	{
		digits[digit][3] = 0;
		changed++;
	}
	if(digits[digit][4] == 1)
	{
		digits[digit][4] = 0;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 1)
	{
		digits[digit][6] = 0;
		changed++;
	}
	return changed;
}

int eight(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 0)
	{
		digits[digit][0] = 1;
		changed++;
	}
	if(digits[digit][1] == 0)
	{
		digits[digit][1] = 1;
		changed++;
	}
	if(digits[digit][2] == 0)
	{
		digits[digit][2] = 1;
		changed++;
	}
	if(digits[digit][3] == 0)
	{
		digits[digit][3] = 1;
		changed++;
	}
	if(digits[digit][4] == 0)
	{
		digits[digit][4] = 1;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 0)
	{
		digits[digit][6] = 1;
		changed++;
	}
	return changed;
}

int nine(int digit)
{
	int changed = 0;

	if(digits[digit][0] == 0)
	{
		digits[digit][0] = 1;
		changed++;
	}
	if(digits[digit][1] == 0)
	{
		digits[digit][1] = 1;
		changed++;
	}
	if(digits[digit][2] == 0)
	{
		digits[digit][2] = 1;
		changed++;
	}
	if(digits[digit][3] == 0)
	{
		digits[digit][3] = 1;
		changed++;
	}
	if(digits[digit][4] == 1)
	{
		digits[digit][4] = 0;
		changed++;
	}
	if(digits[digit][5] == 0)
	{
		digits[digit][5] = 1;
		changed++;
	}
	if(digits[digit][6] == 0)
	{
		digits[digit][6] = 1;
		changed++;
	}
	return changed;
}

int main(int argc, char** argv)
{
	int N;
	cin>>N;

	int a,b;
	int ans;
	for(int i = 0;i<N;i++)
	{
		cin>>a>>b;
		memset(digits,0,sizeof(digits));
		ans = 0;
		int temp = a;
		int a_digit = 0;

		while(temp != 0)
		{
			int remains = temp%10;
			temp /= 10;
			if(remains == 0) zero(a_digit);
			if(remains == 1) one(a_digit);
			if(remains == 2) two(a_digit);
			if(remains == 3) three(a_digit);
			if(remains == 4) four(a_digit);
			if(remains == 5) five(a_digit);
			if(remains == 6) six(a_digit);
			if(remains == 7) seven(a_digit);
			if(remains == 8) eight(a_digit);
			if(remains == 9) nine(a_digit);
			a_digit++;
		}
		int b_digit = 0;
		while(a != 0 || b != 0)
		{
			if(b != 0)
			{
				int remains = b%10;

				if(remains == 0) ans += zero(b_digit);
				if(remains == 1) ans += one(b_digit);
				if(remains == 2) ans += two(b_digit);
				if(remains == 3) ans += three(b_digit);
				if(remains == 4) ans += four(b_digit);
				if(remains == 5) ans += five(b_digit);
				if(remains == 6) ans += six(b_digit);
				if(remains == 7) ans += seven(b_digit);
				if(remains == 8) ans += eight(b_digit);
				if(remains == 9) ans += nine(b_digit);
			}
			else
				ans += none(b_digit);
				

			b /= 10;
			a /= 10;
			b_digit++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
