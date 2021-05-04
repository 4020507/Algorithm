class Solution {
public:
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        map<int,int> m;
        for(int i = 0;i<size;i++)
        {
            m[nums[i]]++;
        }
        
        vector<pair<int,int>> v(m.begin(),m.end());
        
        vector<int> ans;
        sort(v.begin(),v.end(),cmp);
        
        for(int i = 0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
