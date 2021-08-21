#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int sum = 0;
    int len = truck_weights.size();
    int idx = 0;
    
    while(q.size() < bridge_length)
        q.push(0);
    while(idx < len)
    {
        if(sum + truck_weights[idx] - q.front() <= weight)
        {
            sum -= q.front();
            q.pop();
            q.push(truck_weights[idx]);
            sum += truck_weights[idx];
            idx++;
        }
        else
        {
            sum -= q.front();
            q.pop();
            q.push(0);
        }
        answer++;
    }
    while(!q.empty())
    {
        q.pop();
        answer++;
    }
    
    return answer;
}
