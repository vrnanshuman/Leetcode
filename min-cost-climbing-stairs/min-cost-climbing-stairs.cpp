class Solution {
public:
    
    int helper(int index, vector<int> &cost, vector<int> &dp, int& len){
        if(index >= len)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        dp[index] = cost[index] + min(helper(index+1, cost, dp, len), helper(index+2, cost, dp, len));
        return dp[index];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len+1, -1);
        return min(helper(0,cost, dp, len), helper(1, cost, dp, len));
    }
};
