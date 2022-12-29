#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(int i = 0;i<works.size();i++){
        pq.push(works[i]);
    }
    
    int left;
    while(n && !pq.empty()){
        left = pq.top()-1;
        
        if(left > 0){
            pq.push(left);
        }
        
        pq.pop();
        n--;
    }
    
    while(!pq.empty()){
        answer += (pq.top() * pq.top());
        pq.pop();
    }
    return answer;
}
