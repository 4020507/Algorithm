class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        map <int,int> m;
        int size = nums1.size();
        for(int i = 0;i<size;i++)
            for(int j = 0;j<size;j++)
                m[nums1[i] + nums2[j]]++;
        
        for(int i = 0;i<size;i++)
            for(int j = 0;j<size;j++){
                ans += m[-nums3[i]-nums4[j]];
            }
        
        return ans;
    }
};
