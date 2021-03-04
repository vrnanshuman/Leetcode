class Solution {
public:
    
    int helper(vector<vector<int>>& t, vector<vector<int>> &m,int row, int col) {
        if(row == t.size())
            return 0;
        if(m[row][col]!= -1)
            return m[row][col];
        int min_cost = INT_MAX;
        for(int i=col;i<=col+1;i++) {
            min_cost = min(min_cost, t[row][col] + helper(t,m, row+1, i));
        }
        m[row][col] = min_cost;
        return min_cost;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = triangle[rows-1].size();
        vector<vector<int>> m(rows, vector<int>(cols, -1));
        return helper(triangle, m, 0, 0);
    }
};