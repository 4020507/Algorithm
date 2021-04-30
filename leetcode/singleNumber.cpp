class Solution {
public:
    int singleNumber(vector<int>& nums) {
        uint32_t num = 0;
        int size = nums.size();
        for(int i = 0;i<size;i++)
        {
            num = (num^nums[i]);
        }
        
        return num;
    }
};
