class Solution {
public:
    
    int getMaxCost(vector<int>& nums, int start, int end) {
        int len = nums.size();
        vector<int> max_sum(len, 0);
        for(int i=start;i<=end;i++) {
            int prev = i-1 < start ? 0 : max_sum[i-1];
            int prev_prev = i-2 < start ? 0 : max_sum[i-2];
            max_sum[i] = max(prev, nums[i] + prev_prev);
        } 
        return max(max_sum[len-1], max_sum[len-2]);
    }
    
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
            return nums[0];
        if(len==2)
            return max(nums[0], nums[1]);
        return max(getMaxCost(nums, 0, len-2), getMaxCost(nums, 1, len-1));
    }
};