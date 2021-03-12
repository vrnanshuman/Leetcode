class Solution {
    vector<vector<string>> result;
public:
    
    bool isPalindrome(string &s, int &start, int &end) {
        int l, r;
        l=start, r=end;
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++; r--;
        }
        return true;
    }
    
    void helper(string &s, vector<string> v, int start, int end) {
        if(start > end){
            result.emplace_back(v);
        }
        
        for(int k=start;k<=end;k++) {
            if(isPalindrome(s, start, k)){
                v.emplace_back(s.substr(start, k-start+1));
                helper(s,v, k+1, end);
                if(!v.empty())
                    v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        helper(s, {}, 0, s.length()-1);
        return result;
    }
};