class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        int max_value = nums[0];
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            max_value = max(max_value, dp[i]);
        }
        return max_value;
    }
};