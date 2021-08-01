class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        
        set<string> dict;
        for(auto w:wordDict)
            dict.insert(w);
        
        vector<bool> dp(size+1,false);
        
        dp[0] = true;
        
        for(int i = 0;i<size;i++)
        {
            for(int j = i;j>=0;j--)
            {
                string curr = s.substr(j,i-j+1);
                if(dict.find(curr) != dict.end())
                    dp[i+1] = dp[i+1] || dp[j];
                
                
                if(dp[i+1])
                    break;
            }
        }
        
        return dp[size];
    }
};
