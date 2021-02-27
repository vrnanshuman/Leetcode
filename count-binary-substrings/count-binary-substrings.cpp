class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        
        char prev = s[0];
        int count = 1;
        for(int i=1;i<s.length();i++) {
            if(s[i]==prev){
                count++;
            } else {
                groups.emplace_back(count);
                prev = s[i];
                count = 1;
            }
        }
        groups.emplace_back(count);
        count = 0;
        for(int i=0;i<groups.size()-1;i++) {
            count += min(groups[i], groups[i+1]);
        }
        return count;
    }
};