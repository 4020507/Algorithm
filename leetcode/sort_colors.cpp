class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int temp;
        int curr;
        for(int i = 1;i<size;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]>nums[i])
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        
    }
};
