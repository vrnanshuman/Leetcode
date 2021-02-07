class Solution {
    
public:
    
    bool helper(string target, vector<string> &wordDict, unordered_map<string, bool> &m){
        if(target.length() == 0)
            return true;
        
        auto itr1 = m.find(target);
        if(itr1 != m.end())
            return itr1->second;
        
        auto itr = find(wordDict.begin(), wordDict.end(), target);
        if(itr!=wordDict.end()) {
            m.insert({target, true});
            return true;
        }
        
        bool result;
        for(int i=1;i<target.length();i++){
            result = helper(target.substr(0,i), wordDict, m) && helper(target.substr(i), wordDict, m);
            if(result){
                m.insert({target, true});
                return true;
            }
               
        }
        m.insert({target, false});
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> m;
        return helper(s, wordDict,m);
    }
};

