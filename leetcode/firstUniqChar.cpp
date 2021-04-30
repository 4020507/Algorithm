class Solution {
public:
    int firstUniqChar(string s) {
        int ans[27] = {0,};
        int size = s.length();
        for(int i = 0;i<size;i++)
        {
            ans[s[i]-'a']++;
        }
        
        int min = 100000;
        int temp;
        for(int i = 0;i<26;i++)
        {
            if(ans[i] == 1)
            {
                temp = s.find('a' + i);
                if(temp<min)
                    min = temp;
            }
        }
        
        if(min != 100000)
            return min;
        else
            return -1;
    }
};
