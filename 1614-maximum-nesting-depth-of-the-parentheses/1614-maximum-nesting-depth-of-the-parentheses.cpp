class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int currentDepth = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '('){
                currentDepth += 1;
                maxdepth = max(maxdepth, currentDepth);
            } else if(s[i] == ')') {
                currentDepth -=1;
            }
        }
        return maxdepth;
    }
};