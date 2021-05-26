class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int>element;
        solve(0,size,ans,element,nums);
        
        return ans;
    }
    
    void solve(int curr, int size, vector<vector<int>>& ans, vector<int>& element, vector<int>& nums)
    {
        ans.push_back(element);
        
        for(int i = curr;i<size;i++)
        {
            element.push_back(nums[i]);
            solve(i+1,size,ans,element,nums);
            element.pop_back();
        }
    }
    
};
