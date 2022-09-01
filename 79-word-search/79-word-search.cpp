class Solution {
    vector<vector<char>> b;
    vector<vector<bool>> visited;
    string w;
    int m,n;
public:
    
    bool dfs(int row, int col, int currentIdx) {

        if(currentIdx == w.size())
            return true;
        
        if(row<0 || row>=m || col<0 || col>=n)
            return false;
        
        if(b[row][col]!=w[currentIdx]) {
            return false;
        }
            
        
        if(visited[row][col])
            return false;
        visited[row][col] = true;
        bool retval =  dfs(row+1, col, currentIdx+1) || dfs(row-1, col, currentIdx+1) || dfs(row, col+1, currentIdx+1) || dfs(row, col-1, currentIdx+1);
        visited[row][col] = false;
        return retval;
    }
    
    bool checkLetters() {
        unordered_set<char> s;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                s.insert(b[i][j]);
            }
        }
        
        for(int i=0;i<w.length();i++) {
            auto itr = s.find(w[i]);
            if(itr==s.end())
                return false;
        }
        return true;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        w = word;
        m = board.size();
        n = board[0].size();
        int currentIdx = 0;
        
        if(!checkLetters())
            return false;

        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(dfs(i,j, 0))
                    return true;
            }
        }
        return false;
    }
};