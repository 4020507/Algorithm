#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    int c;

    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}
int main(void)
{
    int a, b;
    cin >> a >> b;

    if (a < b)
        swap(a, b);
    return(gcd(a, b));
    
    return 0;

}
