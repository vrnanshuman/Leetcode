class Solution {
public:
    
    int getBinary(string &s) {
        vector<int> m(26,0);
        
        for(char c : s) {
            m[c-'a'] = 1;
        }
        int num = 0;
        
        for(int i=0;i<26;i++) {
            num += m[i]<<(i); 
        }
        return num;
    }
    
    int maxProduct(vector<string>& words) {
        
        int len = 0;
        int maxProd = 0;
        unordered_map<int,int> m;
        
        for(int i=0;i<words.size();i++) {
            m.insert({i, getBinary(words[i])});
        }
        
        for(int i=words.size()-1;i>=0;i--) {
            for(int j=i-1;j>=0;j--) {
                int hasCommon = m[i] & m[j];
                if(!hasCommon){
                    len = words[i].length()*words[j].length();
                    maxProd = max(maxProd,len);
                }
                    
            }
        }     
        return maxProd;
    }
};