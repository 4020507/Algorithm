#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
        long long P,N;
        long long A[100000000];

        cin>>P>>N;
        long long virus = 0;
        for(int i = 0;i<N;i++){
                cin>>A[i];
                virus = (virus * P)%1000000007;
                virus = (A[i] + virus)%1000000007;               
        }
        
        
        cout<<virus;
 return 0;
}
