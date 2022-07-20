class Solution {
public:
    
    int evenLength(string& s, int& n,int i) {
        int l,r;
        l=i;
        r=i+1;
        int palin=0;
        while(l>=0 && r<n && s[l] == s[r]) {
            palin++;
            l--;
            r++;
        }
        return palin*2;
    }
    
    int oddLength(string& s, int& n,int& i) {
        int l,r;
        l=i-1;
        r=i+1;
        int palin=0;
        while(l>=0 && r<n && s[l] == s[r]) {
            palin++;
            l--;
            r++;
        }
        return palin*2+1;
    }
    
    string longestPalindrome(string s) {
        int len = s.length();
        int longestPalin = 0;
        int l, odd, even;
        l=-1;
        for(int i=0;i<s.length();i++) {
            odd = oddLength(s, len, i);
            even = evenLength(s, len, i);
            if(odd > longestPalin) {
                l=i-(odd-1)/2;
                longestPalin = odd;
            }
            if(even > longestPalin) {
                l=i-(even/2)+1;
                longestPalin = even;
            }
        }
        if(l==-1)
            return "";
        return s.substr(l,longestPalin);
    }
};