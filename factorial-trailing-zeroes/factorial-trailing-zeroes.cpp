class Solution {
public:
    int getExponent(int n, int e) {
        int exp = 0;
        for(int i=e; i<=n; i*=e) {
            exp += (n/i); 
        }
        return exp;
    }
    
    int trailingZeroes(int n) {
        int exp2 = getExponent(n, 2);
        int exp5 = getExponent(n, 5);
        
        return min(exp2,exp5);
    }
};
