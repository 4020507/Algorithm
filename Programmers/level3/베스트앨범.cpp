#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<int,pair<int,pair<int,string>>> a,pair<int,pair<int,pair<int,string>>> b)
{
    if(a.first != b.first)
        return a.first > b.first;
    else if(a.second.first != b.second.first)
        return a.second.first > b.second.first;
    else
        return a.second.second.first < b.second.second.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> m;
    map<string,int> m2;
    int size = plays.size();
    for(int i = 0;i<size;i++){
        m[genres[i]] += plays[i];
    }
    
    vector<pair<int,pair<int,pair<int,string>>>> v;

    for(int i = 0;i<size;i++)
    {
        v.push_back({m[genres[i]],{plays[i],{i,genres[i]}}});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    for(int i = 0;i<size;i++)
    {
        m2[v[i].second.second.second]++;
        if(m2[v[i].second.second.second] <= 2)
        {
            answer.push_back(v[i].second.second.first);
        }
    }
        
    return answer;
}
