class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        sol(n,0,ans,"");
        
        return ans;
    }
    
    void sol(int n,int m, vector<string> &ans,string s)
    {
        if(n == 0 && m == 0)
        {
            ans.push_back(s);
            return;
        }
        
        if(n>0)
        {
            sol(n-1,m+1,ans,s+"(");
        }
        if(m>0)
        {
            sol(n,m-1,ans,s+")");
        }
    }
};
