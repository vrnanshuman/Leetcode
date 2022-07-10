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
    
    
    int countComponents(int n, vector<vector<int>>& edges) {

        v = new vector<int>(n);
        rank = new vector<int>(n);
        
        for(int i=0;i<n;i++) {
            (*v)[i] = i;
        }
        for(int i=0;i<n;i++) {
            (*rank)[i] = 1;
        }
        
        for(int i=0;i<edges.size();i++) {
            auto edge = edges[i];
            if(!connected(edge[0], edge[1])) {
                join(edge[0], edge[1]);
            }
        }
        
        unordered_set<int> s;
        for(int i=0;i<n;i++) {
            s.insert(find((*v)[i]));
        }
        return s.size();
    }
    
};