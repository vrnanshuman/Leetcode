class Solution {
    vector<int> *v = nullptr;
public:
    
    int find(int node) {
        while((*v)[node]!=node) {
            node = (*v)[node];
        }
        return node;
    }
    
    void join(int a, int b) {
        if(!connected(a,b)) {
            int roota = find(a);
            int rootb = find(b);
            (*v)[roota] = rootb;
        }
    }
    
    bool connected(int a, int b) {
        if(find(a) == find(b))
            return true;
        return false;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        v = new vector<int>(n);
        
        for(int i=0;i<n;i++) {
            (*v)[i] = i;
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]){
                    join(i,j);
                }
            }
        }
        
        set<int> s;
        for(int i=0;i<n;i++) {
            s.insert(find(i));
        }
        
        return s.size();
        
        
    }
};