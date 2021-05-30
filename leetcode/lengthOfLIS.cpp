class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2500];
        int size = nums.size();
        int num;
        dp[0] = 1;
        for(int i = 1;i<size;i++)
        {
            num = nums[i];
            dp[i] = 1;
            for(int j = 0;j<i;j++)
            {
                if(num > nums[j])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        sort(dp,dp+size);
        
        return dp[size-1];
    }
};
