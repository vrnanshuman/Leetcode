class Solution {
    unordered_map<string, bool> m;
    string str;
    vector<string> results;
    
public:
    
    void process(int idx, string current) {
        if(idx > str.length())
            return;
        if(idx == str.length()) {
            results.push_back(current);
            return;
        }
        
        for(int i=1;i<=str.length();i++) {
            string tmp = str.substr(idx,i);
            if(m.find(tmp) != m.end()) {
                if(current == ""){
                    process(idx+i, tmp);
                } else {
                    process(idx+i, current+" "+tmp);
                }
            }
                
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string s:wordDict) {
            m.insert({s,true});
        }
        
        str = s;
        process(0, "");
        return results;
    }
};