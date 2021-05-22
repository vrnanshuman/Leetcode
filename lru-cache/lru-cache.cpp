class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int,int>>::iterator> hashMap;
    list<pair<int,int>> linkedList;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    pair<int,int> removeFromList(list<pair<int, int>>::iterator itr) {
        auto kVPair = *itr;
        linkedList.erase(itr);
        auto mapItr = hashMap.find(kVPair.first);
        hashMap.erase(mapItr);
        return kVPair;
    }
    
    void addToList(pair<int,int> kVPair) {
        linkedList.push_front(kVPair);
        hashMap.insert({kVPair.first, linkedList.begin()});
    }
    
    int get(int key) {
        auto itr = hashMap.find(key);
        if(itr != hashMap.end()) {
            auto kVPair = removeFromList(itr->second);
            addToList(kVPair);
            return kVPair.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto mapItr = hashMap.find(key);
        if(mapItr != hashMap.end()) {
            auto itr = mapItr->second;
            auto kVPair = *itr;
            kVPair.second = value;
            linkedList.erase(itr);
            linkedList.push_front(kVPair);
            mapItr->second = linkedList.begin();
        } else {
            if(linkedList.size() >= capacity) {
                auto kVPair = linkedList.back();
                auto itr = hashMap.find(kVPair.first);
                hashMap.erase(itr);
                linkedList.pop_back();
                linkedList.push_front({key, value});
                hashMap.insert({key, linkedList.begin()});
            } else {
                linkedList.push_front({key, value});
                hashMap.insert({key, linkedList.begin()});
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