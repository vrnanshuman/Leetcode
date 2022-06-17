class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int l,r;
        char tmp;
        l=0, r=s.size()-1;
        while(l<r) {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};