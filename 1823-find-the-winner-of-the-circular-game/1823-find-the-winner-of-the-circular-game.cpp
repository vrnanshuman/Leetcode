class Solution {
public:
    
    int helper(int n, int k) {
        if(n==1)
            return 0;
        int x = helper(n-1,k);
        int y = (x+k)%n;
        return y;
    }
    
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;
    }
};