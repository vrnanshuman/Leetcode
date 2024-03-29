class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size()-1] = true;
        
        for(int i=nums.size()-2;i>=0;i--) {
            for(int j=1;j<=nums[i];j++) {
                if((i+j) < nums.size() && dp[i+j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};