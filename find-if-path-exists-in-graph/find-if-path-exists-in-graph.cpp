class Solution {
public:
    
    vector<vector<int>> getAdjList(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    
    bool dfs(vector<vector<int>>& adj, int curr, int &dest, vector<bool>& visited) {
        bool pathExists;
        visited[curr] = true;
        if(curr == dest)
            return true;
        
        for(int neighbour : adj[curr]) {
            if(!visited[neighbour]) {
                pathExists = dfs(adj, neighbour, dest, visited);
                if(pathExists)
                    return true;
            }
                
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
           
        vector<vector<int>> adj = getAdjList(edges, n);
        vector<bool> visited(n, false);
        return dfs(adj, source, destination, visited);
        
    }
};