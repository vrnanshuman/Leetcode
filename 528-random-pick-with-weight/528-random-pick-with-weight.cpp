class Solution {
public:
    vector<int> preSum;
    Solution(vector<int>& w) {
        for(int val : w) {
            preSum.emplace_back(val + (preSum.empty() ? 0 :preSum.back()));
        }
    }
    
    int pickIndex() {
        float randNum = (float)rand()/ RAND_MAX;
        int target = randNum * preSum.back();
        return upper_bound(begin(preSum), end(preSum), target) - preSum.begin();
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */