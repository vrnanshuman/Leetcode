class LRUCache {
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> Map;
    list<pair<int, int>> List;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    pair<int,int> Remove(list<pair<int, int>>::iterator itr) {
        pair<int,int> kvPair = *itr;
        Map.erase(kvPair.first);
        List.erase(itr);
        return kvPair;
    }
    
    int get(int key) {
        auto itr = Map.find(key);
        if(itr != Map.end()) {
            // cout<<"Get: Key found in Map "<<endl;
            pair<int, int> kvPair = Remove(itr->second);
            List.push_front(kvPair);
            Map.insert({key, List.begin()});
            return kvPair.second;
        }
        return -1;
    }
    
    
    void put(int key, int value) {
        auto itr = Map.find(key);
        if(itr!= Map.end()) {
            // cout<<"Put: Key found in Map "<<endl;
            pair<int, int> kvPair = Remove(itr->second);
            kvPair.second = value;
            List.push_front(kvPair);
            Map.insert({key, List.begin()});
        } else {
            if(List.size() == size) {
                // cout<<"Put: Size > Capacity "<<endl;
                int delKey = List.back().first;
                Map.erase(delKey);
                List.pop_back();
                List.push_front(make_pair(key, value));
                Map.insert({key, List.begin()});
            } else {
                // cout<<"Put: Size is less than Capacity "<<endl;
                List.push_front(make_pair(key, value));
                Map.insert({key, List.begin()});
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */