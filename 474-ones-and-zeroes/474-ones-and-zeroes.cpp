class Solution {
    unordered_map<int, pair<int,int>> sMap;
    int m1=0;
    int n1=0;
public:
    
    pair<int,int> getCounts(string& s) {
        int ones,zeros;
        ones=zeros=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='1')
                ones++;
            else
                zeros++;
        }
        return {zeros, ones}; 
    }
    
    void populateMap(vector<string> &strs) {
        for(int i=0;i<strs.size();i++) {
            auto counts = getCounts(strs[i]);
            sMap.insert({i, counts});
        }
    }
    
    bool validate(pair<int,int> &p ,int &m, int &n) {
        if(m+p.first<=m1 && n+p.second<=n1){
            return true;
        }
        return false;
    }
    
    int findLargest(vector<string>& strs,int idx ,int m, int n, vector<vector<vector<int>>> &t) {

        if(idx == 0 || m>m1 || n>n1)
            return 0;
        
        if(t[idx][m][n]!=-1)
            return t[idx][m][n];
        auto itr = sMap.find(idx-1);
        pair<int,int> p = (*itr).second;
        if(validate(p, m, n)) {

            t[idx][m][n]= max(1+ findLargest(strs, idx-1, m+p.first, n+p.second, t),
                       findLargest(strs, idx-1, m, n,t));
            return t[idx][m][n];
        }
        t[idx][m][n]= findLargest(strs, idx-1, m, n,t);
        return t[idx][m][n];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        m1=m;
        n1=n;
        populateMap(strs);
        int len = strs.size();
        
        vector<vector<vector<int>>> t(len+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return findLargest(strs, len, 0, 0, t);     
        
    }
};