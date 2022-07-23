class Solution {
    unordered_map<int, list<char>> m;
    vector<int> *v;
    vector<int> *rank;
    
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
            int ranka = (*rank)[roota];
            int rankb = (*rank)[rootb];
            if(ranka > rankb)
                (*v)[rootb] = roota;
            else if (ranka < rankb)
                (*v)[roota] = rootb;
            else {
                (*v)[rootb] = roota;
                (*rank)[roota] += 1;
            }
        }
    }
    
    bool connected(int a, int b) {
        if(find(a) == find(b))
            return true;
        return false;
    }
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        v = new vector<int>(n);
        rank = new vector<int>(n);
        
        for(int i=0;i<n;i++) {
            (*v)[i] = i;
            (*rank)[i] = 1;
        }

        for(int i=0;i<pairs.size();i++) {
            auto pair = pairs[i];
            join(pair[0], pair[1]);
        }
        
        for(int i=0;i<n;i++) {
            int leader = find(i);
            auto itr = m.find(leader);
            char c = s[i];
            if(itr!=m.end()){
                itr->second.push_back(c);
            } else {
                m.insert({leader,{c}});
            }
        }
        for(auto &l: m) {
            if(l.second.size())
                (l.second).sort();
        }
        
        
        string result="";
        for(int i=0;i<n;i++) {
            int leader = find(i);
            
            auto itr = m.find(leader);
            if(itr!=m.end()) {
                result+=(itr->second).front();
                (itr->second).pop_front();
            }
        }
        
        return result;
    }

};