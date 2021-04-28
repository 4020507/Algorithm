class Solution {
    
    int doub(string check)
    {
            if(check == "IV")
            {
                return 4;
            }
            else if(check == "IX")
            {
                 return 9;
            }
            else if(check == "XL")
            {
                return 40;
            }
            else if(check == "XC")
            {
                return 90;
            }
            else if(check == "CD")
            {
                return 400;
            }
            else if(check == "CM")
            {
                return 900;
            }
        return 0;
    }
    
    int solo(char c)
    {
        if(c == 'I')
        {
            return 1;
        }
        else if(c == 'V')
        {
            return 5;
        }
        else if(c == 'X')
        {
            return 10;
        }
        else if(c == 'L')
        {
            return 50;
        }
        else if(c == 'C')
        {
            return 100;
        }
        else if(c == 'D')
        {
            return 500;
        }
        else if(c=='M')
        {
            return 1000;
        }
        
        return 0;
    }
public:
    int romanToInt(string s) {
        int size = s.length();
        int sum = 0;
        
        bool I = false;
        bool X = false;
        bool C = false;
        
        string check;
        int temp;
        
        for(int i = 0;i<size;i++)
        {
            temp = doub(s.substr(i,2));
            if(temp != 0)
            {
                sum += temp;
                i++;
                continue;
            }
            sum += solo(s[i]);
        }
        
        return sum;
    }
};
