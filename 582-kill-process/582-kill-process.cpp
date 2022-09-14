class Solution {
    unordered_map<int, vector<int>> childMap;
    vector<int> killed;
public:
    
    void dfs(int pid) {
        for(int i=0;i<childMap[pid].size();i++) {
            killed.push_back(childMap[pid][i]);
            dfs(childMap[pid][i]);
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        for(int i=0;i<pid.size();i++) {
            childMap[ppid[i]].push_back(pid[i]);
        }
        
        killed.push_back(kill);
        dfs(kill);
        return killed;
    }
};