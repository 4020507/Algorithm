class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string> n;
        
        for(int i = 0;i<nums.size();i++)
        {
            n.push_back(to_string(nums[i]));
        }
        
        string ans = "";
        sort(n.begin(),n.end(),[](string &s1, string &s2){ return s1+s2>s2+s1; });
        
        for(auto i:n)
        {
            ans += i;
        }
        
        while(ans[0] == '0' && ans.length()>1)
            ans.erase(0,1);
        return ans;
    }
};
