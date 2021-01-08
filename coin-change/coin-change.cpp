class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount+1, 100000);
        dp[0] = 0;
        
        for(int i=1;i<=amount;i++) {
            for(int j=0;j<len;j++) {
                int remaining = i - coins[j];
                if(remaining >=0) {
                    dp[i] = min(dp[i], 1 + dp[remaining]);
                }
            }
        }
        return dp[amount] == 100000? -1: dp[amount];
    }
};
