class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<=1)
            return true;
        
        long long int l,r,sum,cLong;
        cLong = c;
        l=0, r=(int)sqrt(c);
        while(l<=r) {
            sum = l*l + r*r;
            if(sum == cLong)
                return true;
            else if(sum<cLong)
                l++;
            else
                r--;
        }
        return false;
    }
};