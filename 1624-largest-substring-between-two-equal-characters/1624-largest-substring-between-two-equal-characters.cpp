class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len, maxLen = -1;
        char c;
        unordered_map<char,int> m;
        
        for(int i=0;i<s.length();i++) {
            c= s[i];
            auto itr = m.find(c);
            if(itr!=m.end()) {
                len = i-itr->second-1;
                if(len >= 0)
                    maxLen = max(maxLen, len);
            } else {
                m.insert({c,i});
            }
        }
        return maxLen;
    }
};