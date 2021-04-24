class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        
        for(int i = 1;i<size;i++)
        {
            if(nums[i] == nums[i-1])
            {
                nums.erase(nums.begin()+i);
                i--;
                size = nums.size();
            }
        }
        return size;
    }
};
