class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int size = digits.size();
        if(digits[size-1]<9)
        {
            digits[size-1] += 1;
            return digits;
        }
        
        bool check = true;
        digits[size-1] = 0;
        for(int i = size-2;i>=0;i--)
        {
            if(check)
            {
                if(digits[i] == 9)
                {
                    digits[i] = 0;
                }
                else
                {
                    digits[i] += 1;
                    check = false;
                    break;
                }
            }
        }
        
        if(check)
        {
            digits.insert(digits.begin(),1);
        }
        
        return digits;
        
    }
};
