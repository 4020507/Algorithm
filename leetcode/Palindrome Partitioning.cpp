class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> v;
        find(s,0,s.length(),v);
        return ans;
    }
    
    void find(string& s, int count, int len, vector<string>& v)
    {
        if(len == count)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i = count;i<len;i++)
        {
            if(check(s.substr(count,i+1)))
            {
                v.push_back(s.substr(count,i+1));
                find(s,i+1,len,v);
                v.pop_back();
            }
        }
    }
    
    bool check(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        
        return true;
    }
};
