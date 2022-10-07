class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        vector<int> missCount(nums.size(),0);
        
        for(int i=1;i<nums.size();i++) {
            missCount[i] = missCount[i-1] + nums[i]-nums[i-1]-1;
        }
        
        auto itr = lower_bound(missCount.begin(), missCount.end(), k);
        if(itr!=missCount.end()) {
            int index = itr-missCount.begin();
            int prevMisses = missCount[index-1];
            int diff = k-prevMisses;
            return nums[index-1]+diff;
        }
        return nums.back()+(k-missCount.back());
    }
};