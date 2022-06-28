class Solution {
public:
    
    bool isValid(vector<vector<int>>& image, int row, int col) {
        int m,n;
        m=image.size()-1;
        n=image[0].size()-1;
        if(row>=0 && row<=m && col>=0 && col<=n)
            return true;
        return false;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        
        int m,n,row,col,nrow,ncol,originalColor;
        pair<int,int> tmp;
        m=image.size()-1;
        n=image[0].size()-1;
        originalColor = image[sr][sc];
        vector<pair<int,int>> neighbors = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(),false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
        // visited[sr][sc] = true;
        
        while(!q.empty()) {
            tmp = q.front();
            q.pop();
            row = tmp.first;
            col = tmp.second;
            
            for(auto neighbor : neighbors) {
                nrow = row+neighbor.first;
                ncol = col+neighbor.second;
                if(isValid(image, nrow, ncol) && image[nrow][ncol] == originalColor) {
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
            
        }
        return image;
        
    }
};