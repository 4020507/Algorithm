#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> v[10001];
bool visited[10001];
void pyramid()
{
    int floor = 2;
    int left = 2;
    int right = 3;
    int num = 2;
    int count = 0;
    int b_l = 1;
    int b_r = 1;
    
    while(num<10001)
    {
        if(num == left)
        {
            v[num].push_back(b_l);
            v[b_l].push_back(num);
            b_l = left;
            left = left + floor;
        }
        else if(num == right)
        {
            v[num].push_back(b_r);
            v[num].push_back(num-1);
            v[b_r].push_back(num);
            v[num-1].push_back(num);
            b_r = right;
            right = right + floor + 1;
        }
        else
        {
            v[num].push_back(num-1);
            v[num].push_back(num-floor);
            v[num].push_back(num-floor+1);
            v[num-1].push_back(num);
            v[num-floor].push_back(num);
            v[num-floor+1].push_back(num);
            
        }
        num++;
        count++;
        if(count == floor)
        {
            floor++;
            count=0;
        }
    }
}
int main(void)
{
    pyramid();
    
    int T;
    cin>>T;
    int start,end,ans;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        memset(visited,false,sizeof(visited));
        cin>>start>>end;
        
        queue<pair<int,int>> q;
        q.push(make_pair(start,0));
        visited[start] = true;
        
        while(!q.empty())
        {
            int curr = q.front().first;
            int count = q.front().second;
            q.pop();
            
            if(curr == end)
            {
                ans = count;
                break;
            }
            for(int i = 0;i<v[curr].size();i++)
            {
                int temp = v[curr][i];
                if(!visited[temp])
                {
                    visited[temp] = true;
                    q.push(make_pair(temp,count+1));
                }
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
        
    }
}
