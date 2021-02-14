class Solution {
public:
    
    void generate(unordered_map<char, vector<string>> &m, vector<string> &result,string s, string &digits, int index) {
        if(index == digits.length()) {
            result.emplace_back(s);
            return;
        }
        auto itr = m.find(digits[index]);
        vector<string> &tmp = itr->second; 
        for(int i=0;i<tmp.size();i++) {
            generate(m, result, s+tmp[i], digits, index+1);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
       unordered_map<char, vector<string>> m = {
           {'2',{"a","b","c"}},
           {'3',{"d","e","f"}},
           {'4',{"g","h","i"}},
           {'5',{"j","k","l"}},
           {'6',{"m","n","o"}},
           {'7',{"p","q","r","s"}},
           {'8',{"t","u","v"}},
           {'9',{"w","x","y","z"}}
       };
        vector<string> result;
       generate(m, result,"",digits, 0);
        return result;
    }
};