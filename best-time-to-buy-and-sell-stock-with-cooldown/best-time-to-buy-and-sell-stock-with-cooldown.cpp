class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1)
            return 0;
        int prev_held, prev_sold, prev_reset;
        int held, sold, reset;
        
        prev_held=prev_sold=INT_MIN;
        prev_reset=0;
        for(int i=0;i<len;i++) {
            reset = max(prev_reset, prev_sold);
            held = max(prev_held, prev_reset - prices[i]);
            sold = prev_held + prices[i];
            prev_reset = reset;
            prev_held = held;
            prev_sold = sold;
        }
        int ret_val = max(reset, sold);
        return ret_val>0 ? ret_val:0;
    }
};
