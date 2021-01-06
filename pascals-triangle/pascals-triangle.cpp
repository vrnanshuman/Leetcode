class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0)
            return {};
        if(numRows==1)
            return {{1}};
        vector<vector<int>> matrix(numRows);
        matrix[0] = {1};
        matrix[1] = {1,1};
        int a,b;
        for(int i=2;i<numRows;i++) {
            for(int j=0;j<=i;j++) {
                a=b=0;
                if(j-1 >=0)
                    a = matrix[i-1][j-1];
                if(j<=i-1)
                    b = matrix[i-1][j];
                matrix[i].emplace_back(a+b);
            }
        }
        return matrix;
    }
};
