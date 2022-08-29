class Solution {
public:
    int minSteps(string s, string t) {
        int minSteps = 0;
        vector<int> smap(26,0), tmap(26,0);
        
        for(char c:s) {
            smap[c-'a']+=1;
        }
        
        for(char c:t) {
            tmap[c-'a']+=1;
        }
        
        for(int i=0;i<26;i++) {
            if(tmap[i]>0) {
                if(smap[i] < tmap[i])
                    minSteps+=tmap[i]-smap[i];
            }
        }
        return minSteps;
    }
};