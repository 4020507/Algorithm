class Solution {
public:
    int ans = 0;

    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        
        for(auto i:nums)
        {
            int temp = prev1;
            prev1 = max(prev2 + i,prev1);
            prev2 = temp;
        }
        
        return prev1;
    }
    
};
