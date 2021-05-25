class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0)
            return 0;
        
        int up = 1;
        int ans = 1;
        
        sort(nums.begin(),nums.end());
        int prev = nums[0];
        
        for(int i = 1;i<size;i++)
        {
            if(nums[i] == prev+1)
            {
                up++;
            }
            else if(nums[i] == prev)
            {
                continue;
            }
            else
            {
                up = 1;
            }
            prev = nums[i];
            ans = max(ans,up);
        }
        
        return ans;
    }
};
