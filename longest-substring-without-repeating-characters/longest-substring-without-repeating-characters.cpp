class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i,j;
        i=j=0;
        int longestSubstring = 0;
        while(j<s.length()) {
            auto itrj = m.find(s[j]);
            if(itrj != m.end())
                itrj->second++;
            else
                m.insert({s[j], 1});
            
            if(m.size() < j-i+1) {
                auto itri = m.find(s[i]);
                if(itri != m.end()) {
                    if(itri->second == 1)
                        m.erase(itri);
                    else
                        itri->second--;
                }
                i++;
            } else if(m.size() == j-i+1) {
                longestSubstring = max(longestSubstring, j-i+1);
            }
            j++;
        }
        return longestSubstring;
    }
};