class Solution {
    vector<vector<string>> result;
    bool m[17][17];
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
            // if(isPalindrome(s, start, k)){
            if(s[start] == s[k] && (k-start<=2 || m[start+1][k-1])) {
                m[start][k] = true;
                v.emplace_back(s.substr(start, k-start+1));
                helper(s,v, k+1, end);
                if(!v.empty())
                    v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        memset(m, false, sizeof(m));
        helper(s, {}, 0, s.length()-1);
        return result;
    }
};