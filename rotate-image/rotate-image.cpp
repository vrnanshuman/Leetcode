class Solution {
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();
        
        for(int i=0;i<row;i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        int tmp_row = 0;
        int tmp_col = col-1;
        for(int i=0;i<row;i++){
            for(int j=1;tmp_row-j>=0;j++) {
                swap(matrix[tmp_row-j][tmp_col], matrix[tmp_row][tmp_col+j]);
            }
            tmp_row++;
            tmp_col--;
        }
    }
};
