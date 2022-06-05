class Solution {
public:
    int longestPalindrome(string s) {
        int middle=0, end=0;
        
        unordered_map<char, int> m;
        for(int i=0;i<s.length();i++) {
            if(m.find(s[i])!=m.end())
                m[s[i]] += 1;
            else
                m.insert({s[i], 1});
        }
        
        for(auto itr : m) {
            if(itr.second%2 == 0)
                end +=itr.second;
            else{
                end += itr.second-1;
                middle = 1;
            }
        }
        return end+middle;
    }
};