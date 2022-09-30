class Solution {
    int num;
    vector<vector<int>> adj;
    vector<int> visited;
public:
    
    bool traverse(int src, int &dest) {
        if(visited[src] == 1)
            return false;
        if(visited[src] == 2)
            return true;
        if(adj[src].size()==0) {
            visited[src] = 2;
            if(src == dest)
                return true;
            return false;
        }
        visited[src] = 1;
        for(auto neighbour : adj[src]) {
            if(!traverse(neighbour, dest))
                return false;
        }
        visited[src] = 2;
        return true;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {       
        adj = vector<vector<int>> (n);
        num = n;
        visited = vector<int>(num, 0);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        return traverse(source, destination);
    }
};