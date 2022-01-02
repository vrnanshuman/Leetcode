class Solution {
public:
    string removeDuplicates(string s) {
        string newString(s.length(), ' ');
        int idx = 0;
        
        for(int i=0;i<s.length();i++) {
            if(idx==0 || s[i] != newString[idx-1]) {
                newString[idx++] = s[i];
            }  else {
                idx--;
                continue;
            }
        }
        newString.erase(idx);
        return newString;
    }
};