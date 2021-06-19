#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0;i<scoville.size();i++)
        q.push(scoville[i]);
    
    while(!q.empty() && q.size()>1)
    {
        int k = q.top();
        
        if(k<K)
        {
            q.pop();
            k += q.top() * 2;
            q.pop();
            q.push(k);
            answer++;
            continue;
        }
        return answer;
    }
    if(q.top() >= K)
        return answer;
    return -1;
}
