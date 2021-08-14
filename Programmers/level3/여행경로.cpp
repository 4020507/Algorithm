#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

bool visited[10000];
vector<string> answer;

void dfs(string curr, vector<vector<string>>& t, vector<string> temp)
{
    if(temp.size() > answer.size())
        answer = temp;
    for(int i = 0;i<t.size();i++)
    {
        if(t[i][0] == curr && !visited[i])
        {
            visited[i] = true;
            temp.push_back(t[i][1]);
            dfs(t[i][1],t,temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    
    answer.push_back("ICN");
    sort(tickets.begin(),tickets.end());
    dfs("ICN",tickets,answer);
    
    return answer;
}
