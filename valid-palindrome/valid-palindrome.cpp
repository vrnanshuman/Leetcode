class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int l, r;
        for(l=0,r=len-1;l<r;) {
            while(l<len && !isalnum(s[l]))
                l++;
            while(r>=0 && !isalnum(s[r]))
                r--;
            if(l>r)
                break;
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++; r--;
        }
        return true;
    }
};