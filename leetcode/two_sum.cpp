class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ans;
        int first;
        bool check = false;
        for(int i = 0;i<size;i++){
            first = nums[i];
            for(int j = i+1;j<size;j++){
                if(first + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    check = true;
                    break;
                }
            }
            if(check)
                break;
        }
        return ans;
    }
};
