#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1e9;
    int right = 0;
    int mid, cnt, i, maxCnt;
    
    for(i = 0;i<stones.size();i++){
        right = max(right,stones[i]);
        left = min(left,stones[i]);
    }
    
    while(left <= right){
        mid = (left + right)/2;
        cnt = 0;
        maxCnt = 0;
        
        for(i = 0;i<stones.size();i++){
            if(stones[i] < mid){
                cnt++;
            }
            else{
                maxCnt = max(cnt,maxCnt);
                cnt = 0;
            }
        }
        maxCnt = max(cnt,maxCnt);
        if(maxCnt < k){
            answer = max(answer, mid);
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    
    return answer;
}
