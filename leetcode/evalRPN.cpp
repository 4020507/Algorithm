class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        
        for(auto i:tokens)
        {
            if(i != "/" && i!="*" && i!="-" && i!="+")
                s.push(i);
            else
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                
                if(i == "+")
                    a = a + b;
                else if(i == "-")
                    a = b - a;
                else if(i == "*")
                    a = a * b;
                else if(i == "/")
                    a = b/a;
                s.push(to_string(a));
            }
        }
        
        return stoi(s.top());
    }
};
