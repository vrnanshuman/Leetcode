class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int l,r;
        l=r=0;
        int maxLength = 0;
        while(r<s.length()) {
            if(m.find(s[r]) == m.end()) {
                m.insert(s[r]);
                maxLength = max(maxLength, (int)m.size());
                r++;
            } else {
                while(l<r && s[l]!=s[r]) {
                    m.erase(s[l]);
                    l++;
                }
                m.erase(s[l]);
                l++;
            }
        }
        return maxLength;
    }
};