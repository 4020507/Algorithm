class Solution {
public:
    int climbStairs(int n) {
        
        int start = 1;
        int prev = 1;
        int save = 1;
        for(int i = start;i<n;i++)
        {
            save = start;
            start = start + prev;
            prev = save;
        }
        
        return start;
    }
};
