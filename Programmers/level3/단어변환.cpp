#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int answer;
bool check[51];
void dfs(string curr, string target, vector<string>& word,int count)
{
    if(curr == target)
    {
        answer = min(answer,count);
        return;
    }
    
    for(int i = 0;i<word.size();i++)
    {
        if(check[i])
            continue;
        int same = 0;
        string s = word[i];
        for(int j = 0;j<s.length();j++)
        {
            if(s[j] != curr[j])
            {
                same++;
            }
            if(same == 2)
                break;
        }
        
        if(same == 1)
        {
            check[i] = true;
            dfs(s,target,word,count+1);
            check[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    answer = 51;
    memset(check,false,sizeof(check));
    
    dfs(begin,target,words,0);
    
    if(answer == 51)
        return 0;
    return answer;
}
