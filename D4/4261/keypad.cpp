#include <iostream>
#include <string.h>
using namespace std;

bool detect(int num,char c)
{
    switch(num)
    {
        case 2:
            if(c == 'a' || c == 'b' || c == 'c')
                return true;
            else
                return false;
        case 3:
            if(c == 'd' || c == 'e' || c == 'f')
                return true;
            else
                return false;
        case 4:
            if(c == 'g' || c == 'h' || c == 'i')
                return true;
            else
                return false;
        case 5:
            if(c == 'j' || c == 'k' || c == 'l')
                return true;
            else
                return false;
		case 6:
            if(c == 'm' || c == 'n' || c == 'o')
                return true;
            else
                return false;
		case 7:
            if(c == 'p' || c == 'q' || c == 'r' || c == 's')
                return true;
            else
                return false;
		case 8:
            if(c == 't' || c == 'u' || c == 'v')
                return true;
            else
                return false;
		case 9:
            if(c=='w' || c == 'x' || c == 'y' || c == 'z')
                return true;
            else
                return false;
        default:
            return false;
    }
}
int main(void)
{
    int T;
    cin>>T;
    
    string order;
    int N;
    string input[1000];
    int size;

    bool possible;
    int ans;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>order>>N;
        ans = 0;
        for(int i = 0;i<N;i++)
            cin>>input[i];
        
        size = order.length();
        
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<size;j++)
            {
                possible = detect(order[j] - '0',input[i][j]);
                if(!possible)
                    break;
            }
            if(possible)
                ans++;
        }
       
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
