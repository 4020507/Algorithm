class Solution {
public:
    bool isPalindrome(string s) {
        string modify = "";
        int size = s.length();
        for(int i = 0;i<size;i++)
        {
            if((s[i]>= 'A' && s[i]<= 'Z') || (s[i] >= 'a' && s[i]<='z') || (s[i] >='0' && s[i]<='9'))
            modify += s[i];
        }
        transform(modify.begin(),modify.end(),modify.begin(),::tolower);
        size = modify.length();

        int divide = size/2;
        
        bool check = true;
        for(int i = 0;i<divide;i++)
            {
                if(modify[i] != modify[size-i-1])
                {
                    check = false;
                    break;
                }
            }

        return check;
    }
};
