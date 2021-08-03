class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int size = nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<size;i++)
        {
            
            int start = i + 1;
            int end = size - 1;
            int target = -nums[i];
            
            while(start<end)
            {
                int sum = nums[start] + nums[end];
                
                if(sum > target)
                    end--;
                else if(sum < target)
                    start++;
                else
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[start]);
                    v.push_back(nums[end]);
                    
                    while(nums[start] == v[1] && start < end)
                        start++;
                    while(nums[end] == v[2] && start < end)
                        end--;
                    ans.push_back(v);
                }
            }
            
            while(i+1<size && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};
