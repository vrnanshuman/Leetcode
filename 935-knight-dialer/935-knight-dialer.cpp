class Solution {
    
    unordered_map<string, int> keyMap = {
        {"0,0", 1},
        {"0,1", 2},
        {"0,2", 3},
        {"1,0", 4},
        {"1,1", 5},
        {"1,2", 6},
        {"2,0", 7},
        {"2,1", 8},
        {"2,2", 9},
        {"3,1", 0},
    };
    
    vector<pair<int,int>> moves = {
        {2,1},{-2,1},{1,2},{-1,2},{2,-1},{-2,-1},{1,-2},{-1,-2}
    };
    vector<vector<vector<int>>> m;
public:
    
    bool isValidPosition(int row, int col) {
        if((row == 3 && col == 1) || (row>=0 && row<3 && col>=0 && col<3))
            return true;
        return false;
    }
    
    int getPaths(int row, int col, int len) {
        if(!isValidPosition(row, col))
            return 0;
        if(len == 0) {
            return 1;
        }
        if(m[len][row][col]!=-1)
            return m[len][row][col];
        int paths = 0;
        for(int i=0;i<moves.size();i++) {
            paths = (paths + getPaths(row+moves[i].first, col+moves[i].second,len-1))%1000000007;
        }
        m[len][row][col] = paths;
        return paths;
    }
    
    int knightDialer(int n) {
        if(n==1)
            return 10;
        vector<pair<int,int>> startingPos;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) {
                startingPos.push_back({i,j});
            }
        }
        startingPos.push_back({3,1});
        m = vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(3, -1)));
        int paths = 0;
        for(auto start:startingPos) {
            paths = (paths + getPaths(start.first, start.second,n-1))%1000000007;
        }
        return paths;
    }
};