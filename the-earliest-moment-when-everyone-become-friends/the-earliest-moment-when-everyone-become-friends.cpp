class Solution {
    vector<int> *v = nullptr;
    unordered_map<int,int> m;
public:
    
    int find(int node) {
        if((*v)[node] == node)
            return node;
        return (*v)[node]=find((*v)[node]);
    }
    
    void join(int a, int b, int t) {
        if(!connected(a,b)) {
            int roota = find(a);
            int rootb = find(b);
            (*v)[rootb] = roota;
            auto itr = m.find(roota);
            if(itr!=m.end()) {
                itr->second = t;
            } else {
                m.insert({roota,t});
            }
        }
    }
    
    bool connected(int a, int b) {
        if(find(a) == find(b))
            return true;
        return false;
    }
    
    
    int earliestAcq(vector<vector<int>>& logs, int n) {

        v = new vector<int>(n);
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });
        
        for(int i=0;i<n;i++) {
            (*v)[i] = i;
        }

        for(int i=0;i<logs.size();i++) {
            auto log = logs[i];
            if(!connected(log[1], log[2])) {
                join(log[1], log[2], log[0]);
            }
        }
        
        unordered_set<int> s;
        for(int i=0;i<n;i++) {
            s.insert(find((*v)[i]));
        }
        if(s.size()!=1)
            return -1;
        return m.find(find((*v)[0]))->second;
        
    }
    
};