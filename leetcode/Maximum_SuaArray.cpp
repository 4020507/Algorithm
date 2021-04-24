class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        long long sum[30000];
        for(int i = 0;i<size;i++)
        {
            if(i == 0)
            {
                sum[i] = nums[i];
            }
            else
            {
                if(nums[i] > 0 && sum[i-1] > 0)
                {
                    sum[i] = nums[i] + sum[i-1];
                }
                else if(sum[i-1] < 0 && nums[i] < 0)
                {
                    sum[i] = nums[i];
                }
                else if(sum[i - 1] > nums[i])
                {
                    sum[i] = nums[i] + sum[i-1];
                }
                else
                {
                    sum[i] = nums[i];
                }
            }
        }
        sort(sum,sum+size);
        
        return sum[size-1];
    }
};
