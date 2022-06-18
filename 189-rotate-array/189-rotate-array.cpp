class Solution {
public:
    int gcd(int a, int b) {
        if(a>b)
            return gcd(b,a);
        int c;
        while(b%a != 0) {
            c = b;
            b = a;
            a = c%a; 
        }
        return a;
    }
    
    void rotate(vector<int>& nums, int k) {
        

        int n = nums.size();
        if(k == 0 || n==1)
            return;
        if(k > n)
            k = k%n;

        int j, cur, prev;
        int width = gcd(k, n);
        cout<<width<<endl;
        for(int i=0;i<width;i++) {
            j = i;
            do{
                if(j==i) {
                    prev = nums[j];
                } else{
                    cur = nums[j];
                    nums[j] = prev;
                    prev = cur;
                    
                }
                j = (j+k)%n;
            }while(j!=i);
            nums[j] = prev;
        }
        
    }
};