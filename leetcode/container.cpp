class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int mini;
        int ans = 0;
        
        int i = 0;
        int j = height.size()-1;
        
        while(i<j)
        {
            mini = min(height[i],height[j]);
            ans = max(ans,mini * (j - i));
            
            while(mini >= height[i] && i<j) i++;
            while(mini >= height[j] && j>i) j--;
        }
        
        return ans;
    }
};
