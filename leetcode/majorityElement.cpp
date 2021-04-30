class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int prev = nums[0];
        int count = 1;
        for(int i = 1;i<size;i++)
        {
            if(nums[i] == prev){
                count++;
                if(count>size/2)
                    return prev;
            }
            else
            {
                count = 1;
                prev = nums[i];
            }
        }
        
        return prev;
    }
};
