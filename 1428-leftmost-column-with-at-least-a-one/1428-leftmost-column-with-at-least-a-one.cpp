/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m, n, row, col, idx=-1;
        vector<int> dims = binaryMatrix.dimensions();
        m = dims[0];
        n = dims[1];
        row = 0; col = n-1;
        
        while(row>=0 && row<m && col>=0 && col<n) {
            if(binaryMatrix.get(row, col) == 1) {
                idx = col;
                col--;
            }
            else
                row++;
        }
        return idx;
    }
};