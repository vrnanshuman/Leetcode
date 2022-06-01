class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sMap(26,0);
        vector<int> tMap(26,0);
        
        for(int i=0;i<s.length();i++) {
            sMap[s[i]-'a'] += 1;
        }
        int toSearch;
        for(int i=0;i<t.length();i++) {
            toSearch = t[i] - 'a';
            if(sMap[toSearch] == 0)
                return false;
            else
                sMap[toSearch] -= 1;
        }
        
        for(int i=0;i<26;i++) {
            if(sMap[i] > 0)
                return false;
        }
        return true;
    }
};