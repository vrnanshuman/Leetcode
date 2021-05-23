class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 1)
            return strs[0];
        string lcp = "";
        
        for(int i=0;i<strs[0].length();i++) {
            string root = strs[0];
            for(int j=1;j<strs.size();j++) {
                if(i >= strs[j].length() || root[i]!=strs[j][i])
                    return lcp;
            }
            lcp += root[i];
        }
        return lcp;
    }
};