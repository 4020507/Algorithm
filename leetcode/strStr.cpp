class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle == "")
            return 0;
        int size1 = haystack.length();
        int size2 = needle.length();
        
        if(size2 > size1)
            return -1;
        else if(size1 == size2)
        {
            if(haystack == needle)
                return 0;
            else
                return -1;
        }
        string temp;
        int ans = -1;
        for(int i = 0;i<size1;i++)
        {
            if(i + size2 -1 >size1)
                break;
            temp = haystack.substr(i,size2);
            if(temp == needle){
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
