class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = INT_MIN;
        int curr_min = INT_MAX;
        
        int len = prices.size();
        for(int i=0;i<len;i++) {
            int profit = prices[i] - curr_min;
            if(profit > max_profit) {
                max_profit = profit;
            }
            if(prices[i] < curr_min) {
                curr_min = prices[i];
            }
        }
        return max_profit > 0 ? max_profit : 0;
    }
};
