class Solution {
    struct Node {
        string name;
        double value;
    };
    unordered_set<string> visited;
    unordered_map<string, vector<Node>> m;
    double result;
public:
    
    void dfs(string src, string &dest, double value) {
        if(visited.find(src)!=visited.end())
            return;
        if(m.find(src) == m.end())
            return;
        if(src.compare(dest) == 0) {
            result = value;
            return;
        }
        visited.insert(src);
        for(auto neighbour : m[src]) {
            dfs(neighbour.name, dest, value*neighbour.value);
            if(result!=-1.0)
                return;
        }
        visited.erase(src);
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i=0;i<equations.size();i++) {
            m[equations[i][0]].push_back(Node{equations[i][1], values[i]});
            m[equations[i][1]].push_back(Node{equations[i][0], 1/values[i]});            
        }
        vector<double> results;
        for(auto query: queries) {
            visited.clear();
            result = -1.0;
            dfs(query[0], query[1], 1);
            results.push_back(result);
        }
        return results;
    }
};