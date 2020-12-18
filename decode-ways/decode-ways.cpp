class Solution {
    int helper(int index, string s, vector<int> &v) {
        if(index == s.length()) {
            return 1;
        }
        if(s[index] == '0') {
            return 0;
        }
        if(index == s.length() - 1) {
            return 1;
        }
        if(v[index] != -1) {
            return v[index];
        }
        int result = 0;
        if(index+1 < s.length()) {
            int num = (s[index]-'0')*10 + (s[index+1]-'0');
            if(num <= 26) {
                    result += helper(index+2, s, v); 
            }
        }
        result += helper(index+1, s, v);
        v[index] = result;
        return result;
    }
public:
    int numDecodings(string s) {
        if(s.length() == 0) {
            return 0;
        }
        vector<int> v(s.length(),-1);
        return helper(0,s, v);
    }
};
