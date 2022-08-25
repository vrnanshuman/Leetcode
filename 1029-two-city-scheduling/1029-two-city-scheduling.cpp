class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0]-a[1] < b[0]-b[1];
        });
        int minCost = 0;
        int i=1;
        int n=costs.size()/2;
        for(vector<int> cost:costs) {
            minCost += i<=n ? cost[0] : cost[1];
            i++;
        }
        return minCost;
    }
};