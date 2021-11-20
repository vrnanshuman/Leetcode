class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1, mid;
        
        while(l<=r){
            mid = l+(r-l)/2;
            // cout<<"mid "<<mid<<endl;
            // cout<<"value "<<nums[mid]<<endl;
            if(nums[mid]<target && (mid==nums.size()-1 || nums[mid+1]>=target))
                return mid+1;
            else if(nums[mid] < target)
                l=mid+1;
            else
                r=mid-1;
        }
        return mid;
    }
};