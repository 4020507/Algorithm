#include<math.h>
class Solution {
public:
    int reverse(int x) {
        if (x <= -2147483648 || x >=  2147483647)
            return 0;
        long long ans = 0;
        bool check = true;
        
        if(x<0){
            check = false;
            x = -x;
        }
        
        
        while(x>0)
        {
            ans *= 10;
            ans += x%10;
            x /= 10;
        }
        if(!check)
            ans = -ans;
        if(ans <= -2147483648 || ans >=  2147483647)
            return 0;
        return ans;
    }
};
