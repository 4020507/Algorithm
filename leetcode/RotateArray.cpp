class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0)
            return;
        int size = nums.size();
        
        vector<int> temp(size);
        
        for(int i = 0;i<size;i++)
            temp[i] = nums[i];
        
        for(int i = 0;i<size;i++)
        {
            nums[(i+k)%size] = temp[i];
        }
    }
};
