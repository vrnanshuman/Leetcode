class Solution {
public:
    
    bool isVowel(char& c) {
        if(c=='a' || c=='A' ||
          c=='e' || c=='E' ||
          c=='i' || c=='I'||
          c=='o' || c=='O'||
          c=='u' || c=='U')
            return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int l,r;
        char tmp;
        
        l=0,r=s.length()-1;
        
        while(l<r) {
            while(l<s.length() && !isVowel(s[l]))
                l++;
            while(r>=0 && !isVowel(s[r]))
                r--;
            if(l<r) {
                tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l++;
                r--;
            }
        }
        return s;
    }
};