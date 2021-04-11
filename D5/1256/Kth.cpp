#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    int N,size;
    string s;
    string divide[400];
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N;
        cin>>s;
        size = s.length();
        for(int i = 0;i<size;i++)
        {
            divide[i] = s.substr(i);
        }
        sort(divide,divide+size);
       
        cout<<"#"<<test_case<<" "<<divide[N-1]<<endl;
    }
}
