class Solution {
    vector<vector<int>> paths = {};
public:
    
    void dfs(vector<vector<int>>& adj, vector<int> path, int curr, int &dest) {
        if(curr == dest)
            paths.push_back(path);
        
        for(auto neighbour : adj[curr]) {
            path.push_back(neighbour);
            dfs(adj, path, neighbour, dest);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size()-1;
        dfs(graph, {0}, 0, n);
        return paths;
    }
};