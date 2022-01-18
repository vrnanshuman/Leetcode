class Solution {
    
public:
    
    vector<pair<int,int>> getNeighbours(vector<vector<int>>& grid, int row, int col) {
        vector<pair<int,int>> directions = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        int newRow, newCol;
        vector<pair<int, int>> neighbours;
        for(pair<int,int> dir : directions) {
            newRow = row+dir.first;
            newCol = col+dir.second;
            if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && (grid[newRow][newCol] == 0))
                neighbours.push_back({newRow, newCol});
        }
        return neighbours;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] || grid[grid.size()-1][grid[0].size()-1])
            return -1;
        
        int row, col, distance;
        queue<pair<int, int>> Queue;
        grid[0][0] = 1;
        Queue.push({0,0});
        
        while(!Queue.empty()) {
            pair<int,int> front = Queue.front();
            row = front.first;
            col = front.second;
            Queue.pop();
            distance = grid[row][col];
            if((row == (grid.size()-1)) && (col == (grid[0].size()-1)))
                    return distance;
            
            for(pair<int,int> neighbour : getNeighbours(grid, row, col)) {
                grid[neighbour.first][neighbour.second] = distance+1;
                Queue.push(neighbour);
            }
        }
        return -1;
    }
};