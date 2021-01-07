class Solution {
public:
    
    int helper(int n, vector<int> &dp) {
        if(n == 1)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i*i<=n;i++) {
            if(n%i == 0){
                if(helper(n-i, dp) == 0) {
                    dp[n] = 1;
                    return 1;
                }
                int val = n/i;
                val = n-val;
                if(i!=n && val!=0 && helper(n-(n/i), dp) == 0) {
                    dp[n] = 1;
                    return 1;
                }
            }
            
        }
        dp[n] = 0;
        return 0;
    }
    
    bool divisorGame(int N) {
        vector<int> dp(N+1, -1);
        return helper(N, dp);
    }
};
