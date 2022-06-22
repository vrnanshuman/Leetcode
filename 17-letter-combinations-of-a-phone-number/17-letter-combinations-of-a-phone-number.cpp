class Solution {
    unordered_map<char, vector<char>> m = {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}}
    };
public:
    
    void generate(string &digits, int idx, string current, vector<string> &results) {
        if(idx == digits.length()) {
            results.emplace_back(current);
            return;
        }
        for(char c:m[digits[idx]]) {
            generate(digits, idx+1, current+c, results);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) {
            return {};
        }
        vector<string> results;
        generate(digits, 0, "" , results);
        return results;
    }
};