class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m, n;
        m = matrix.size();
        n = matrix[0].size();
        vector<int> ordering;
        
        int x,y;
        for(int i=m-1;i>=0;i--) {
            x=i, y=0;
            int item = matrix[x][y];
            while(x<m && y<n) {
                if(matrix[x][y] != item)
                    return false;
                ordering.emplace_back(matrix[x][y]);
                x++;
                y++;
            }
        }
        for(int i=1;i<n;i++) {
            x=0, y=i;
            int item = matrix[x][y];
            while(x<m && y<n) {
                if(matrix[x][y] != item)
                    return false;
                ordering.emplace_back(matrix[x][y]);
                x++;
                y++;
            }
        }
        for(int val : ordering) {
            cout<<val<<" ";
        }
        return true;
    }
};