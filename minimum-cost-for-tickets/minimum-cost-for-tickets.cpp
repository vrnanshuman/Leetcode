class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        int len = days.size();
        int day_index = 0;
        int prev = 0;
        for(int i=1;i<=365 && day_index<days.size();i++){
            
            if(i<days[day_index]) {
                dp[i] = prev;
                continue;
            }
            int tmp;
            tmp = dp[i-1] + costs[0];
            if(days[day_index] - 7 >= 0)
                tmp = min(tmp, dp[days[day_index]-7] + costs[1]);
            else
                tmp = min(tmp, costs[1]);
            if(days[day_index] - 30 >= 0)
                tmp = min(tmp, dp[days[day_index]-30] + costs[2]);
            else
                tmp = min(tmp, costs[2]);
            dp[i] = tmp;
            prev = tmp;
            day_index++;
        }
        return dp[days[len-1]];
    }
};