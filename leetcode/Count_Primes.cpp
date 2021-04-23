class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;

        int count = 1;
        
        vector<bool> v(n,false);
        int limit = sqrt(n);
        for(int i = 3;i<n;i+=2)
        {
            if(!v[i])
            {
                count++;
                if(i>limit)
                    continue;
                for(int j = i * i;j<n;j += i)
                    v[j] = true;
            }
        }
        return count;
    }
};
