#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<float,int> a, pair<float,int> b)
{
    if(a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map <int,int> m;
    vector<pair<float,int>> v;
    int total = stages.size();
    
    for(int i = 0;i<total;i++)
    {
        m[stages[i]]++;
    }
    
    for(int i = 1;i<=N;i++)
    {
        if(total > 0){
            v.push_back(make_pair(((float)m[i]/(float)total),i));
            total = total - m[i];
        }
        else
        {
            v.push_back(make_pair(0,i));
        }
        
    }
    
    sort(v.begin(),v.end(),cmp);
    
    for(int i = v.size()-1;i>=0;i--)
    {
       answer.push_back(v[i].second);
    }
    return answer;
}
