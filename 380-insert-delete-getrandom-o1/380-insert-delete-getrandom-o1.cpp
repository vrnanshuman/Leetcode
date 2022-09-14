class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> indexMap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(indexMap.find(val)==indexMap.end()) {
            indexMap.insert({val, v.size()});
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(indexMap.find(val) != indexMap.end()) {
            int idx = indexMap[val];
            int last = v[v.size()-1];
            //swap
            v[idx] = last;
            indexMap[last] = idx;
            v.pop_back();
            indexMap.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int r = rand()%v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */