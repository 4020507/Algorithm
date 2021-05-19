class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int size = prices.size();
        if(size<=1)
            return 0;
        
        int minprice = prices[0];
        int maxprofit = 0;
        
        for(int i = 0;i<size;i++)
        {
            if(minprice > prices[i])
            {
                minprice = prices[i];
            }
            else if(minprice<prices[i])
            {
                maxprofit = maxprofit>(prices[i] - minprice)?maxprofit:(prices[i]-minprice);
            }
        }
        
        return maxprofit;
        
    }
};
