class Solution {
public:
    
    void generate(vector<string> &results, string s, int open, int closed) {
        
        if(open > closed)
            return;
        
        if(open == 0 && closed == 0) {
            results.emplace_back(s);
            return;
        }
        if(open > 0){
            generate(results, s+"(", open-1, closed);
        }
        if(closed > 0){
            generate(results, s+")", open, closed-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        generate(results, "", n, n);
        return results;
    }
};