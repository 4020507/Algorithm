#include <iostream>

using namespace std;

int main(void)
{
    int T;
    cin>>T;
    
    string num;
    int a,b;
    bool alice;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>num;
        char cal[1001];
        int size = num.size();
        for(int i = 0;i<size;i++)
            cal[i] = num[i];
        alice = true;
        size = size - 1;
        while(size+1 != 1)
        {
            alice = !alice;
            char c1 = num[size]; size--;
            char c2 = num[size]; size--;
            
            int num1 = c1 - '0';
            int num2 = c2 - '0';
            
            num1 = num1 + num2;
            
            if(num1>=10)
            {
                c1 = (char)(num1/10) + '0';
                c2 = (char)(num1%10) + '0';
                num[++size] = c1;
                num[++size] = c2;
            }
            else
            {
                num[++size] = (char)num1 + '0';
            }
        }
        cout<<"#"<<test_case<<" ";
        if(!alice)
            cout<<"A"<<endl;
        else
            cout<<"B"<<endl;
    }
    
}
