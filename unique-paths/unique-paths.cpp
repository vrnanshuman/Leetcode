class Solution {
    int helper(int x, int y, int m, int n, vector<vector<int>> &grid) {
        if(x >= m || y >= n)
            return 0;
        if(x==m-1 && y==n-1)
            return 1;
        if(grid[x][y] != -1)
            return grid[x][y];
        int unique_ways = 0;
        unique_ways += helper(x, y+1, m, n, grid);
        unique_ways += helper(x+1, y, m, n, grid);
        grid[x][y] = unique_ways;
        return unique_ways;
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        return helper(0,0,m,n,grid);
    }
};
