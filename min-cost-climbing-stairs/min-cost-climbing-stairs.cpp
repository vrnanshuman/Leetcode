class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0;
        int b = 0;
        int minCost = 0;
        
        for(int c : cost) {
            minCost = min(c+a, c+b);
            a = b;
            b = minCost;
        }
        return min(a,b);
    }
};