class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return 1;
        vector<int> dp(len, 1);
        
        for(int i=1;i<len;i++) {
            int max_sub = 0;
            for(int j=0;j<i;j++) {
                if(nums[i] > nums[j]) {
                    max_sub = max(max_sub, dp[j]);
                }
            }
            dp[i] = 1 + max_sub;
        }
        return *max_element(dp.begin(), dp.end());
    }
};