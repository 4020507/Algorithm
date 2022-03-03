class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = nums[0];
        
        for(int i = 1,tMax = ans, tMin = ans;i<nums.size();i++)
        {
            if(nums[i] < 0)
                swap(tMax,tMin);
            
            tMax = max(nums[i],tMax * nums[i]);
            tMin = min(nums[i],tMin * nums[i]);
            
            ans = max(tMax,ans);
        }
        
        return ans;
    }
};
