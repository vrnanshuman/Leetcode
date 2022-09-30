class Solution {
    vector<vector<int>> adj;
    vector<int> result;
    string label;
    vector<bool> visited;
public:
    
    // void print(int i, vector<int> c) {
    //     cout<<i<< " "<<label[i] << " : "<<c[label[i]-'a']<<endl; 
    // }
    
    vector<int> getNodes(int i) {
        vector<int> counts(26,0);
        if(visited[i]) {
            return counts;
        }
            
        visited[i] = true;
        
        if(adj[i].size() == 0) {
            counts[label[i]-'a'] = 1;
            result[i] = 1;
            // print(i, counts);
            return counts;
        }
            
        char l = label[i];
        counts[l-'a'] = 1;
        vector<int> tmp;
        for(auto neighbour : adj[i]) {
            tmp = getNodes(neighbour);
            for(int j=0;j<26;j++)
                counts[j]+=tmp[j];
        }
        result[i] = counts[l-'a'];
        // print(i, counts);
        return counts;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj = vector<vector<int>>(n);
        result = vector<int>(n,0);
        label = labels;
        visited = vector<bool>(n, false);
        
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> tmp = getNodes(0);
        
        return result;
    }
};