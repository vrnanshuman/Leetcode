class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int l,len,r,minSize = 0;
        l=r=0;
        
        
        while(r<nums.size()) {
            sum += nums[r];
            
            while(sum >= target && l<=r) {
                len = r-l+1;
                minSize = minSize == 0 ? len : min(minSize, len);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minSize;
        
    }
};