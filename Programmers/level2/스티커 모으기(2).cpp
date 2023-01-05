#include <vector>
using namespace std;

int dp[100000];

int solution(vector<int> sticker)
{
    int answer = sticker[0];
    
    if(sticker.size() == 1){
        return answer;
    }
    
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    int i;
    
    for(i = 2;i<sticker.size()-1;i++){
        dp[i] = max(dp[i-1],dp[i-2]+sticker[i]);
    }
    
    answer = dp[sticker.size()-2];
    
    dp[0] = 0;
    dp[1] = sticker[1];
    
    for(i = 2;i<sticker.size();i++){
        dp[i] = max(dp[i-1],dp[i-2]+sticker[i]);
    }
    
    answer = max(answer,dp[sticker.size()-1]);
    
    return answer;
}
