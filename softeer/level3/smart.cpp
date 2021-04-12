#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
bool visited[20000];
int N,K;
int count;
string s;

int main(int argc, char** argv)
{
        
        cin>>N>>K;

        cin>>s;

        count = 0;
        memset(visited,false,sizeof(visited));
        int init = -K;
        int curr;
        for(int i = 0;i<N;i++)
        {
                if(s[i] == 'H'){
                        for(int j = init;j<=K;j++)
                        {
                                curr = i + j;

                                if(curr>=0 && curr<N && !visited[curr] && s[curr] == 'P')
                                {
                                        count++;
                                        visited[curr] = true;
                                        break;
                                }
                        }
                }
        }
        
        cout<<count<<endl;
 return 0;
}
