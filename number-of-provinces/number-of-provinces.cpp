class Solution {
    vector<int> *v = nullptr;
    vector<int> *rank = nullptr;
public:
    
    int find(int node) {
        if((*v)[node] == node)
            return node;
        return (*v)[node]=find((*v)[node]);
    }
    
    void join(int a, int b) {
        if(!connected(a,b)) {
            int roota = find(a);
            int rootb = find(b);
            if((*rank)[a] > (*rank)[b]) {
                (*v)[rootb] = roota;
            } else if((*rank)[a] < (*rank)[b]) {
                (*v)[roota] = rootb;
            } else {
                (*v)[rootb] = roota;
                (*rank)[roota] +=1; 
            }
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
        rank = new vector<int>(n);
        
        for(int i=0;i<n;i++) {
            (*v)[i] = i;
        }
        for(int i=0;i<n;i++) {
            (*rank)[i] = 1;
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