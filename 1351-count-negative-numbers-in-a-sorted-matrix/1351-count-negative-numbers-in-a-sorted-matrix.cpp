class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows,cols, row,col,count = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        row = 0;
        col = cols-1;
        while(row<rows && rows>=0 && col<cols && col>=0) {
            if(grid[row][col] < 0){
                count += rows - row;
                col -= 1;
            } else {
                row++;
            }
        }
        return count;
    }
};