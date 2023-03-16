#include<iostream>
using namespace std;

int n, k;
int arr[1000010];
int prefix[1000010];

int main(int argc, char** argv)
{
        int i;
        int a, b;

        cin >> n >> k;
        for(i=1;i<=n;i++)
        {
                cin >> arr[i];
        }
        
        for(i=1;i<=n;i++)
        {
                prefix[i] = prefix[i-1] + arr[i];
        }

        for(i=0;i<k;i++)
        {
                cin >> a >> b;

                printf("%.2lf\n", 1.0 * (prefix[b] - prefix[a-1]) / (b - a + 1));
        }
}
