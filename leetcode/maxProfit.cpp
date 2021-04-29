class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0];
        int profit = 0;
        int size = prices.size();
        for(int i = 1;i<size;i++)
        {
            if(curr<prices[i])
            {
                profit += prices[i] - curr;
                curr = prices[i];
            }
            else if(curr > prices[i])
            {
                curr = prices[i];
            }
        }
        
        return profit;
    }
};
