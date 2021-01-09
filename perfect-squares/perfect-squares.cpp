class Solution {
public:
    int numSquares(int n) {
        if(n<=1)
            return n;
        
        vector<int> dp(n+1, n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++) {
                int sq = j*j;
                if(i-sq >= 0){
                    dp[i] = min(dp[i], 1 + dp[i-sq]);
                }
            }
        }
        return dp[n];
    }
};
