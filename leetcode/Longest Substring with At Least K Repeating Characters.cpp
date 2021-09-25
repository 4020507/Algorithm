class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return sol(s,0,n,k);
    }
    
    int sol(string &s, int start, int end, int k)
    {
        if(end < k)
            return 0;
        
        int alpha[26] = {0,};
        
        for(int i = start; i < end;i++)
        {
            alpha[s[i] - 'a']++;
        }
        for(int mid = start; mid<end;mid++)
        {
            if(alpha[s[mid] - 'a'] >= k)
                continue;
            int next = mid+1;
            while(next < end && alpha[s[next]- 'a'] < k)
                next++;
            return max(sol(s,start,mid,k),sol(s,next,end,k));
        }
        return (end - start);
    }
};
