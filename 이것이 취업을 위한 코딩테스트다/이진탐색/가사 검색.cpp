#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> order[10001];
vector<string> reorder[10001];

int binary_search(vector<string>& v, string a, string z)
{
    int left = lower_bound(v.begin(),v.end(),a) - v.begin();
    int right = upper_bound(v.begin(),v.end(),z) - v.begin();
    
    return right - left;
}

string replacing(string s, string from, string to)
{
    string result = s;
    int pos = 0;
    
    while((pos = result.find(from,pos)) != string::npos)
    {
        result.replace(pos,from.size(),to);
        pos += to.size();
    }
    
    return result;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for(auto w: words)
    {
        int len = w.length();
        order[len].push_back(w);
        string r = w;
        reverse(r.begin(),r.end());
        reorder[len].push_back(r);
    }
    
    for(int i = 0; i < 10001;i++)
    {
        sort(order[i].begin(),order[i].end());
        sort(reorder[i].begin(),reorder[i].end());
    }
    
    for(auto q:queries)
    {
        int len = q.length();
        int pos = 0;
        if(q[0] != '?')
        {
            answer.push_back(binary_search(order[len],replacing(q,"?","a"),replacing(q,"?","z")));
        }
        else
        {
            reverse(q.begin(),q.end());
            
            answer.push_back(binary_search(reorder[len],replacing(q,"?","a"),replacing(q,"?","z")));
        }
    }
    return answer;
}
