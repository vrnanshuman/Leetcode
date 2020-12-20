class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minsum(m, vector<int>(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                minsum[i][j] = grid[i][j];
                int up = INT_MAX;
                int left = INT_MAX;
                if(i-1 >= 0) {
                    up = minsum[i-1][j];
                }
                if(j-1 >= 0) {
                    left = minsum[i][j-1];
                }
                if(i != 0 || j != 0) {
                    minsum[i][j] = grid[i][j] + min(up, left);
                }    
            }
        }
        return minsum[m-1][n-1];
        
    }
};
