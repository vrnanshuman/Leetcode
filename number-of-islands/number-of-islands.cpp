class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int x, int y, int &m, int &n) {
        if(x<0 || x>=m || y<0 || y>=n)
            return;
        if(grid[x][y] == '0' || grid[x][y] == '2')
            return;
        grid[x][y] = '2';
        dfs(grid, x-1, y, m, n);
        dfs(grid, x+1, y , m, n);
        dfs(grid, x, y-1, m, n);
        dfs(grid, x, y+1, m, n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m, n;
        m = grid.size();
        n = grid[0].size();
        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i,j,m,n);
                    islands++;
                }
            }
        }
        return islands;
    }
};
