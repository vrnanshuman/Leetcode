class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        if(len == 0)
            return 0;
        vector<vector<int>> dp(costs.size()+1, vector<int>(3));
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        
        for(int i=1;i<=len;i++){
            dp[i][0] = costs[i-1][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i-1][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i-1][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        return min(dp[len][0], min(dp[len][1],dp[len][2]));
    }
};