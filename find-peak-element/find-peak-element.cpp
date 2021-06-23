class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l,r;
        l=0, r= nums.size()-1;
        
        while(l<=r) {
            int mid = l+(r-l)/2;
            int left = mid-1 >= 0 ? nums[mid-1] : INT_MIN;
            int right = mid+1 >= nums.size() ? INT_MIN : nums[mid+1];
            
            if(nums[mid] > left && nums[mid]>right) {
                return mid;
            } else if(nums[mid] >= left) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return 0;
    }
};