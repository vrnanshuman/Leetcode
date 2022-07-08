class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        int len, count, diff;
        len = nums.size();
        vector<int> preSum(len, 0);
        preSum[0]=nums[0];
        
        for(int i=1;i<len;i++) {
            preSum[i] = nums[i] + preSum[i-1];
        }
        
        m.insert({0,1});
        count = 0;
        for(int i=0;i<len;i++) {
            diff = preSum[i] - goal;
            auto itr = m.find(diff);
            if(itr!=m.end()) {
                count+=itr->second;
            }
            auto itr2 = m.find(preSum[i]);
            if(itr2!=m.end()) {
                itr2->second++;
            } else {
                m.insert({preSum[i], 1});
            }
            
        }
        return count;
    }
};