class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> range;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int size = intervals.size();

        for(int i = 1;i<size;i++)
        {
            if(end >= intervals[i][0])
            {
                end = max(intervals[i][1],end);
            }
            else
            {
                range.push_back(start);
                range.push_back(end);
                ans.push_back(range);
                range.clear();
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        range.push_back(start);
        range.push_back(end);
        ans.push_back(range);
        return ans;
    }
};
