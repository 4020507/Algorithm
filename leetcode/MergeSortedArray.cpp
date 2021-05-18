class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n == 0)
            return;
        int end = m + n -1;
        int nums1_end = m-1;
        int nums2_end = n-1;
        
        while(nums1_end>=0 && nums2_end>=0)
        {
            if(nums1[nums1_end] > nums2[nums2_end])
            {
                nums1[end--] = nums1[nums1_end--];
            }
            else
            {
                nums1[end--] = nums2[nums2_end--];
            }
        }
        while(nums2_end >= 0)
        {
            nums1[end--] = nums2[nums2_end--];
        }

    }
};
