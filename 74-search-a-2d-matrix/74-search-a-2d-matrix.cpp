class Solution {
public:
    
    pair<int,int> getRowCol(vector<vector<int>>& matrix, int index) {
        return {index/matrix[0].size(), index%matrix[0].size()};
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l, r, mid, rows, cols, row, col;
        
        rows = matrix.size();
        cols = matrix[0].size();
        l=0,r=(rows*cols)-1;
        
        while(l<=r) {
            mid = l+(r-l)/2;
            pair<int,int> p = getRowCol(matrix, mid);
            row = p.first;
            col = p.second;
            
            if(matrix[row][col] == target)
                return true;
            else if(target < matrix[row][col]) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return false;
    }
};