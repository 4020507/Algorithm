class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int sum = 0;
        int curr = 0;
        int start = 0;
        for(int i = 0;i<size;i++)
        {
            curr += gas[i] - cost[i];
            if(curr < 0)
            {
                sum += curr;
                curr = 0;
                start = i + 1;
            }
        }
        sum += curr;
        
        if(sum < 0)
            return -1;
        else
            return start;
    }
};
