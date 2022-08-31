class Solution {
    vector<vector<int>> b;
    vector<vector<bool>> visited;
    vector<vector<pair<int,int>>> toCrush;
    int m,n;
public:
    
    void dfs(int row, int col, int &key, vector<pair<int,int>> &tmp ,bool &done) {
        if(row<0 || row>=m || col<0 || col>=n)
            return;
        if(visited[row][col])
            return;
        if(b[row][col]!=key)
            return;
        visited[row][col] = true;
        tmp.push_back({row,col});
        dfs(row+1, col, key, tmp,done);
        dfs(row-1, col, key, tmp,done);
        dfs(row, col+1, key, tmp,done);
        dfs(row, col-1, key, tmp,done);
    }
    
    void horizontal(int row, int col, int &key, vector<pair<int,int>> &tmp) {
        if(row<0 || row>=m || col<0 || col>=n)
            return;
        
        for(int i=col;i<n;i++) {
            visited[row][i] = true;
            if(b[row][i] == key) {
                tmp.push_back({row,i});
            } else {
                break;
            }
        }
    }
    
    void vertical(int row, int col, int &key, vector<pair<int,int>> &tmp) {
        if(row<0 || row>=m || col<0 || col>=n)
            return;
        
        for(int i=row;i<m;i++) {
            visited[i][col] = true;
            if(b[i][col] == key) {
                tmp.push_back({i, col});
            } else {
                break;
            }
        }
    }
    
    void adjust() { 
        for(int col=0;col<n;col++) {
            int idx = m-1;
            for(int row = m-1;row>=0;row--) {
                if(b[row][col]!=0){
                    b[idx][col] = b[row][col];
                    idx--;
                }
            }
            for(int row=idx;row>=0;row--) {
                b[row][col] = 0;
            }
        }
    }
    
    void flagBoard() {
        for(auto tmp:toCrush) {
            for(pair<int,int> p : tmp) {
                b[p.first][p.second] = 0;
            }
        } 
    }
    
    void print() {
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                cout<<b[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        b = board;
        m = board.size();
        n = board[0].size();
        bool done=false;
        
        do {
            done = false;
            visited = vector<vector<bool>>(m, vector<bool>(n, false));
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    vector<pair<int,int>> tmp;
                    int key = b[i][j];
                    if(key!=0){
                        horizontal(i,j,key,tmp);
                        if(tmp.size()>2){
                            done = true;
                            toCrush.push_back(tmp);
                        }
                    }
                    tmp.clear();
                    if(key!=0){
                        vertical(i,j,key,tmp);
                        if(tmp.size()>2){
                            done = true;
                            toCrush.push_back(tmp);
                        }
                    }
                }
            }
            print();
            cout<<endl<<endl;
            flagBoard();
            print();
            if(done)
                adjust();
            toCrush.clear();
            cout<<endl<<endl;
        }while(done);
        return b;
    }
};