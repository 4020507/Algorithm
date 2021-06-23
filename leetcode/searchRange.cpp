class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if(nums.size() == 0)
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        
        vector<int>::iterator low1,low2;
        low1 = lower_bound(nums.begin(),nums.end(),target);
        low2 = lower_bound(nums.begin(),nums.end(),target+1);
        
        if(low1 != nums.end() && *low1 == target)
        {
            v.push_back(low1 - nums.begin());
            v.push_back(low2 - nums.begin() - 1);
            return v;
        }
        else
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
            
    }
};
