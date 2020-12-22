class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_square_side = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == '0'){
                    continue;
                }
                int top = 0;
                int left = 0;
                int diag = 0;
                if(i-1 >= 0)
                    top = result[i-1][j];
                if(j-1 >= 0)
                    left = result[i][j-1];
                if(i-1 >=0 && j-1 >= 0)
                    diag = result[i-1][j-1];
                int tmp = 1 + min(top, min(left, diag));
                result[i][j] = tmp;
                max_square_side = max_square_side > tmp ? max_square_side: tmp;
            }
        }
        return max_square_side*max_square_side;
    }
};
