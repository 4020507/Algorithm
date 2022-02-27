class Solution {
public:
    int ans = 0;
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        
        for(int i = 1;i<=amount;i++)
        {
            for(auto j:coins)
            {
                if(j<=i)
                {
                    dp[i] = min(dp[i],dp[i-j]+1);
                }
            }
        }
        
        return dp[amount]>amount?-1:dp[amount];
    }
    
};
