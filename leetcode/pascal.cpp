class Solution {
public:
    int triangle[465];
    
    vector<vector<int>> generate(int numRows) {
        
        triangle[0] = 1;
        int floor = 1;
        int count = 0;
        int curr = 1;
        vector<int> temp;temp.push_back(1);
        vector<vector<int>> v;
        v.push_back(temp);
        temp.clear();
        while(floor < numRows)
        {
            if(count == 0 || count == floor)
            {
                triangle[curr] = 1;
                temp.push_back(triangle[curr]);
            }
            else
            {
                triangle[curr] = triangle[curr-floor] + triangle[curr-floor-1];
                temp.push_back(triangle[curr]);
            }
            
            if(floor == count)
            {
                count = 0;
                floor++;
                v.push_back(temp);
                temp.clear();
            }
            else
            {
                count++;
            }
            curr++;
        }   
        
        return v;
    }
};
