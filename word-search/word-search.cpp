class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string &word, int index, int row, int col, int &m, int &n) {
        if(index == word.length())
            return true;
        if(row<0 || row>=m || col<0 || col>=n)
            return false;
        if(board[row][col] == '$')
            return false;
        if(board[row][col] != word[index])
            return false;
        board[row][col] = '$';
        bool result = dfs(board, word, index+1, row+1, col, m, n) ||
               dfs(board, word, index+1, row-1, col, m, n) ||
               dfs(board, word, index+1, row, col+1, m, n) ||
               dfs(board, word, index+1, row, col-1, m, n);
        board[row][col] = word[index];
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, 0, i, j, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};