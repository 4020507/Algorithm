#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    double position[20];
    double weight[20];
    int N;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N;
        for(int i = 0;i<N;i++)
            cin>>position[i];
        for(int i = 0;i<N;i++)
            cin>>weight[i];
        double mid;
        cout<<"#"<<test_case<<" ";
        for(int i = 0;i<N-1;i++)
        {
            mid = (position[i] + position[i+1])/2;
            double left = position[i];
            double right = position[i+1];
            int count = 0;
            double sum = 0;
            while(count<100){
                mid = (left + right)/2;
                sum = 0;
                for(int j = 0;j<=i;j++)
                    sum += weight[j]/((mid - position[j])*(mid - position[j]));
                for(int k = i+1;k<N;k++)
                    sum -= weight[k]/((position[k] - mid) * (position[k] - mid));
                if(sum == 0)
                    break;
                if(sum>0)
                    left = mid;
                else
                    right = mid;
               
                count++;
            }
            printf("%.10lf ",mid);
        }
        
        cout<<endl;
    }
}
