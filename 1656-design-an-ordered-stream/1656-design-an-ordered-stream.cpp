class OrderedStream {
    vector<string> v;
    int ptr;
public:
    OrderedStream(int n) {
        v = vector<string>(n,"");
        ptr = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey-1] = value;
        int curr = ptr;
        while(ptr<v.size() && v[ptr]!="")
            ptr++;
        return vector<string>(v.begin()+curr, v.begin()+ptr);
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */