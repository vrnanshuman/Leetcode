class Solution {
    vector<pair<int,int>> neighbors = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
    };
public:
    
    bool isValid(vector<vector<char>>& grid, int row, int col) {
        int m,n;
        m=grid.size()-1;
        n=grid[0].size()-1;
        if(row>=0 && row<=m && col>=0 && col<=n)
            return true;
        return false;    
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>> &visited) {
        visited[row][col] = true;
        int nrow, ncol;
        for(auto neighbor: neighbors) {
            nrow = row + neighbor.first;
            ncol = col + neighbor.second;
            if(isValid(grid, nrow, ncol) && grid[nrow][ncol]=='1' && !visited[nrow][ncol])
                dfs(grid, nrow, ncol, visited);
        }
        
    }

    
    int numIslands(vector<vector<char>>& grid) {
        
        int m,n;
        m = grid.size();
        n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid, i, j,visited);
                    islands+=1;
                }
                    
            }
        }
        return islands;
    }
};