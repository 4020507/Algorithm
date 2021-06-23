#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    stack<pair<int,int>> s;
    int prev = priorities[0];
    bool inside[100] = {false,};
    while(s.size() < priorities.size())
    {
        for(int i = 0;i<priorities.size();i++)
        {
            if(prev >= priorities[i] && !inside[i])
            {
                prev = priorities[i];
                s.push(make_pair(i,prev));
                inside[i] = true;
            }
            else if(!inside[i])
            {
                while(prev < priorities[i] && !s.empty())
                {
                    inside[s.top().first] = false;
                    s.pop();
                    
                    if(s.size() == 0)
                        break;
                    prev = s.top().second;
                    if(prev >= priorities[i])
                    {
                        prev = priorities[i];
                        s.push(make_pair(i,prev));
                        inside[i] = true;
                    }
                }
                if(s.size() == 0)
                {
                    prev = priorities[i];
                    s.push(make_pair(i,prev));
                    inside[i] = true;
                }
            }
        }
    }
    
    int find = -1;
    int order = s.size();
    
    while(find != location && !s.empty())
    {
        find = s.top().first;
        
        if(find == location)
        {
            answer = order;
            break;
        }
        order--;
        s.pop();
    }
    
    return answer;
}
