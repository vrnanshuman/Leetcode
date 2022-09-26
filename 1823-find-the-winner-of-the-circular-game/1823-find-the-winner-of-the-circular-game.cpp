class Solution {
public:
    
    int findTheWinner(int n, int k) {
        if(n==1)
            return 1;
        int x = 0;
        int y;
        int num = 2;
        while(num<=n) {
            y = (x+k)%num;
            x = y;
            num++;
        }
        return y+1;
    }
};