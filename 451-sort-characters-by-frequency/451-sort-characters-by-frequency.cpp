class Solution {
public:
    string frequencySort(string s) {
        if(s.length() <= 2)
            return s;
        
        unordered_map<char, int> m;
        
        for(int i=0;i<s.length();i++) {
            if(m.find(s[i]) != m.end()) {
                m[s[i]] += 1;
            } else {
                m.insert({s[i],1});
            }
        }
        
        sort(s.begin(), s.end(), [&m](const char &a, const char &b) {
            int aCount = m[a];
            int bCount = m[b];
            if(aCount == bCount)
                return a > b;
            return aCount>bCount;
        });
        
        return s;
    }
};