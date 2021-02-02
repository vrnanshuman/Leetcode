class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int top,bottom, mid;
        top = 0;
        bottom = m-1;
        while(top<=bottom) {
            mid = (top + bottom)/2;
            if((mid == 0 && target<= matrix[mid][n-1]) || (target <= matrix[mid][n-1] && target > matrix[mid-1][n-1]))
               break;
            else if(target > matrix[mid][n-1])
               top = mid+1;
            else
               bottom = mid -1;
        }
        int row = mid;
        int left, right;
        left = 0;
        right = n-1;

        while(left<=right){
            mid = (left+right)/2;
            if(matrix[row][mid] == target){
                return true;
            } else if(target < matrix[row][mid])
                right = mid-1;
            else 
                left = mid+1;
        }
        return false;
    }
};