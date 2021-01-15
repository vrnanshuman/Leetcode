class Solution {
public:
    int dfs(int row, int col, int &m, int &n, vector<vector<int>> &grid) {
        if(row<0 || row>=m || col<0 || col>=n)
            return 0;
        if(grid[row][col]<=0)
            return 0;
        
        grid[row][col] = -1;
        int islands = dfs(row+1, col,m,n,grid) +
                      dfs(row, col+1, m,n,grid) +
                      dfs(row-1, col,m,n,grid) + 
                      dfs(row, col-1, m,n,grid);
        
        return islands+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m,n,i,j, max_islands, tmp;
        m = grid.size();
        n = grid[0].size();
        max_islands=0;
        
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j]>0){
                    tmp = dfs(i,j,m,n,grid);
                    max_islands = max(max_islands, tmp);
                }
                    
            }
        }
        return max_islands;
    }
};
