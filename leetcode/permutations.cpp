class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        dfs(0,nums,result);
        return result;
    }
    
    void dfs(int curr,vector<int>& nums,vector<vector<int>>& result)
    {
        if(curr == nums.size())
        {
            result.push_back(nums);
        }
        
        for(int i = curr;i<nums.size();i++)
        {
            swap(nums[curr],nums[i]);
            dfs(curr+1,nums,result);
            swap(nums[curr],nums[i]);
        }
    }
};
