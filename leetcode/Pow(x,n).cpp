class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        
        while(n)
        {
            if(n%2)
            {
                result = n>0 ? result * x : result/x;
            }
            
            x *= x;
            n /= 2;
        }
        
        return result;
    }
};
