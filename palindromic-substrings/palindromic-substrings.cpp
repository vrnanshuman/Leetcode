class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int count = 0;
        for(int i=0;i<len;i++) {
            for(int x=1;x<len;x++) {
                if(i-x >=0 && i+x<len){
                    if(s[i-x] == s[i+x])
                        count++;
                    else
                        break;
                }
            }
            
            for(int x=0; x<len;x++) {
                if(i-x >=0 && i+x+1 < len) {
                    if(s[i-x] == s[i+x+1])
                        count++;
                    else
                        break;
                }
            }
        }
        return count+len; 
    }
};
