class Solution {
    
public:
    
    unordered_map<string, vector<string>> adjacent;
    unordered_set<string> visited;
    
    void DFS(string firstEmail, vector<string>& mergedAccount) {
        
        visited.insert(firstEmail);
        mergedAccount.push_back(firstEmail);
        
        vector<string> neighbours = adjacent[firstEmail];
        for(string email : neighbours) {
            if(visited.find(email)==visited.end()){
                DFS(email, mergedAccount);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            
        for(vector<string> account : accounts) {
            string firstEmail = account[1];
            for(int j=2;j<account.size();j++) {
                string email = account[j];
                adjacent[firstEmail].push_back(email);
                adjacent[email].push_back(firstEmail);
            }
        }
        
        vector<vector<string>> merged;
        for(vector<string>& account:accounts) {
            string name = account[0];
            string firstEmail = account[1];
            
            if(visited.find(firstEmail) == visited.end()) {
                vector<string> mergedAccount;
                mergedAccount.push_back(name);
                DFS(firstEmail, mergedAccount);
                sort(mergedAccount.begin()+1, mergedAccount.end());
                merged.push_back(mergedAccount);
            }
        }
        return merged;
    }
};