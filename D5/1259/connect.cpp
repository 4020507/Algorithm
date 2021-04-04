#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n;
int main(void)
{
    int T;
    cin>>T;
    
    int input;
    int front,back;
    int tool[40][2];
    string s;
    bool check;
    bool visited[40];
    int count;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>n;

        s = "";     
		memset(visited,false,sizeof(visited));
        check = false;
        
        for(int i = 0;i<n;i++)
        {
            cin>>front>>back;
            tool[i][0] = front;
            tool[i][1] = back;
        }

        s = to_string(tool[0][0]) + " " + to_string(tool[0][1]);
        back = tool[0][1];
        front = tool[0][0];
        visited[0] = true;
		
        while(1){
            for(int i = 1;i<n;i++)
            {
                if(!visited[i] && back == tool[i][0])
                {
                    s += " " + to_string(tool[i][0]) + " " + to_string(tool[i][1]);
                    back = tool[i][1];
                    visited[i] = true;
                    check = true;
                    break;
                }
                if(i == n-1)
                    check = false;
            }
            if(check)
                check = false;
            else
                break;
        }

            for(int i = 1;i<n;i++)
            {
                if(visited[i]){
                    continue;
                }
                else if(front == tool[i][1])
                {
                    s.insert(0,to_string(tool[i][0]) + " "+to_string(tool[i][1]) + " ");
                    front = tool[i][0];
                    visited[i] = true;
                    i = 0;
                }
            }
        
        cout<<"#"<<test_case<<" "<<s<<endl;
    }
}
