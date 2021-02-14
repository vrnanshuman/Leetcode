class Solution {
public:
    
    void generate(vector<string> & result, int open, int close, string s, int &n) {
        if(s.size() == 2*n) {
            result.emplace_back(s);
        }
        if(open<n)
            generate(result, open+1, close, s+"(", n);
        if(close<open)
            generate(result, open, close+1, s+")", n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, 0,0,"", n);
        return result;
    }
};