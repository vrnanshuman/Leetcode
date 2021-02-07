class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int len = time.size();
        int a_mod, b_mod;
        vector<int> m(60,0);
        int pairs = 0;
        for(int i=0;i<len;i++) {
            a_mod = time[i]%60;
            if(a_mod == 0) {
                pairs += m[0];
                m[0] += 1;
            } else {
                b_mod = 60-a_mod;
                pairs += m[b_mod];
                m[a_mod] += 1;
            }
                
        }
        return pairs;
    }
};