class Solution {
public:
    long long int mod = 1e9+7;
    
    int helper(vector<vector<vector<int>>> &t, int &m, int &n, int moves, int row, int col) {
        if(moves == 0 && (row<0 || row>m-1 || col<0 || col>n-1))
            return 1;
        if(moves != 0 && (row<0 || row>m-1 || col<0 || col>n-1))
            return 0;
        if(moves == 0 && !(row<0 || row>m-1 || col<0 || col>n-1))
            return 0;
        if(t[moves][row][col]!=-1)
            return t[moves][row][col];
        t[moves][row][col] = ((helper(t,m,n, moves-1, row+1, col)+
                         helper(t,m,n, moves-1, row-1, col))%mod +
                         (helper(t,m,n, moves-1, row, col+1) +
                         helper(t,m,n, moves-1, row, col-1))%mod) %mod ;
        return t[moves][row][col];
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        long long int paths = 0;
        vector<vector<vector<int>>> t(N+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        for(int k=1;k<=N;k++){
            paths += (helper(t, m,n, k, i,j)%mod);
        }
        return paths%mod;
    }
};