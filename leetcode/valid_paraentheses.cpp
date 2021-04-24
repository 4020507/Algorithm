class Solution {
public:
    bool isValid(string s) {

        int size = s.length();
        stack <char> st;
        char temp;
        for(int i = 0;i<size;i++)
        {
            if(s[i] == '[' ||
              s[i] == '{' ||
              s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                    return false;
                temp = st.top();
                st.pop();
                if((s[i] == ']' && temp == '[') ||
                   (s[i] == '}' && temp == '{') ||
                   (s[i] == ')' && temp == '('))
                {
                    continue;
                }
                else
                    return false;
            }
        }
        
        if(!st.empty())
            return false;
        
        return true;
    }
};
