class Solution {
    unordered_map<string, bool> m;
    string str;
    vector<int> t;
public:
    
    bool process(int idx) {
        // if(idx > str.length())
        //     return false;
        if(idx == str.length())
            return true;
        if(t[idx]!=-1)
            return t[idx]==0 ?false:true;
        for(int i=1;i<=str.length();i++) {
            string tmp = str.substr(idx,i);
            if(m.find(tmp) != m.end()) {
                if(process(idx+i)) {
                    t[idx] = 1;
                    return true;
                }
            }
        }
        t[idx] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string s:wordDict) {
            m.insert({s,true});
        }
        
        str = s;
        t = vector<int>(s.length(),-1);
        return process(0);
    }
};