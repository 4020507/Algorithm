class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s = countAndSay(n-1);
        
        char count = '1';
        int len = s.length();
        char prev = s[0];
        string ans = "";
        if(len == 1)
        {
            ans += count;
            ans += prev;
            return ans;
        }
        for(int i = 1;i<len;i++)
        {
            if(prev == s[i])
                count++;
            else
            {
                ans += count;
                ans += prev;
                prev = s[i];
                count = '1';
            }
        }
        ans += count;
        ans += prev;
        return ans;
    }
};
