class Solution {
public:
    
    string getHash(string &s) {
        if(s.length() == 1)
            return "$";
        string hash = "";
        for(int i=1;i<s.length();i++) {
            
            hash += to_string((s[i] - s[i-1] + 26)%26) + "#";
        }
        return hash;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        vector<vector<string>> result;
        unordered_map<string, vector<string>> sMap;
        unordered_map<string, vector<string>>::iterator itr;
        string hash;
        for(string s : strings) {
            hash = getHash(s);
            itr = sMap.find(hash);
            if(itr!=sMap.end()) {
                itr->second.emplace_back(s);
            } else {
                sMap.insert({hash, {s}});
            }
        }
        
        for(itr = sMap.begin();itr!=sMap.end();itr++) {
            result.emplace_back(itr->second);
        }
        return result;
    }
};