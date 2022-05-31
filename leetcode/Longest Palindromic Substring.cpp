class Solution {
public:
    string ans = "";
    string longestPalindrome(string s) {
        
        check(0,s.length(),s);
        return ans;
    }
    
    void check(int start, int end, string s)
    {
        if(start == end){
            if(ans.length() < 1)
                ans = s[start];
            return;
        }
        if(start > end)
            return;
        
        if(s[start] != s[end])
        {
            check(start+1,end,s);
            check(start,end-1,s);
            return;
        }
        int o_start = start;
        int o_end = end;
        start++;
        end--;
        while(start <= end)
        {
            if(s[start] != s[end])
            {
                check(start+1,end,s);
                check(start,end-1,s);
                return;
            }
            start++;
            end--;
        }
        
        if(ans.length() < o_end - o_start + 1)
        {
            ans = "";
            
            for(int i = o_start;i<=o_end;i++)
                ans += s[i];
        }
    }
};
