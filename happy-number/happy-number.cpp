class Solution {
public:
    
    int sumDigits(int n) {
        int sum = 0;
        int rem;
        while(n) {
            rem = n%10;
            sum += rem*rem;
            n = n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow,fast;
        slow = sumDigits(n);
        fast = sumDigits(sumDigits(n));
        
        while(slow != fast) {
            slow = sumDigits(slow);
            fast = sumDigits(sumDigits(fast));
        }
        if(slow == 1)
            return true;
        return false;
    }
};