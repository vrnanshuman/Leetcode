class Solution {
public:
    int jump(vector<int>& nums) {
     
        if(nums.size() <=2)
            return nums.size()-1;
        vector<int> dp(nums.size(), 0);
        dp[nums.size()-1] = 0;
        for(int i=nums.size()-2;i>=0;i--) {
            int min_value = nums.size()-1;
            for(int j=1;j<=nums[i];j++) {
                if((i+j) < nums.size())
                    min_value = min(min_value, 1 + dp[i+j]);
            }
            dp[i] = min_value;
        }
        return dp[0];
    }
};