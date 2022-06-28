class Solution {
    vector<pair<int,int>> neighbors = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
    };
    int maxArea = 0;
public:
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        int m,n;
        m=grid.size()-1;
        n=grid[0].size()-1;
        if(row>=0 && row<=m && col>=0 && col<=n)
            return true;
        return false;    
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>> &visited, int &area) {
        visited[row][col] = true;
        area += 1;
        int nrow, ncol;
        for(auto neighbor: neighbors) {
            nrow = row + neighbor.first;
            ncol = col + neighbor.second;
            if(isValid(grid, nrow, ncol) && grid[nrow][ncol]==1 && !visited[nrow][ncol])
                dfs(grid, nrow, ncol, visited, area);
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m,n;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int area;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                if(grid[i][j]==1 && !visited[i][j]){
                    area = 0;
                    dfs(grid, i, j,visited, area);
                    maxArea = max(maxArea, area);
                }
                    
            }
        }
        return maxArea;
    }
};