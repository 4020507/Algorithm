class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> ans;
        if(len == 0)
            return ans;
        
        ans.push_back("");
        vector<string> letters = {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        
        for(auto digit : digits)
        {
            vector<string> append;
            for(auto letter : letters[digit-'0'])
            {
                for(auto a : ans)
                {
                    append.push_back(a + letter);
                }
            }
            ans = append;
        }
        
        return ans;
    }
};
