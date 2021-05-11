class Solution {
public:
    vector<int> ans;
    
    Solution(vector<int>& nums) {
        ans = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ans;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffle(ans);
        
        random_shuffle(shuffle.begin(),shuffle.end());
        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
