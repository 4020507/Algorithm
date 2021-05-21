#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    
    string A,B,comp;
    int len,size;
    int count;
    int prev;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>A>>B;
        len = B.length();
        size = A.length();
        count = 0;
        cout<<"#"<<test_case<<" ";
        if(size<len){
            cout<<size<<endl;
            continue;
        }
        for(int i = 0;i<=size - len;i++)
        {
            comp = A.substr(i,len);
            if(comp == B)
            {
                i = i+len-1;
            }
            count++;
            prev = i;
        }

        cout<<count + size - prev - 1<<endl;
    }
}
