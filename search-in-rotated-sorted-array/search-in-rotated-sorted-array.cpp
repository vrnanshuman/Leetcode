class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        int l,r, mid;
        l=0;
        r=len-1;
        while(l<=r) {
            mid = (r+l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>=nums[l]) {
            //Greater side
               if(target<nums[l])//is target on other side
                   l=mid+1;
                else{
                    if(target<nums[mid])
                        r=mid-1;
                    else
                        l=mid+1;
                }
            } else {
                //Lesser side
                if(target<nums[l]){
                    if(target<nums[mid])
                        r=mid-1;
                    else
                        l=mid+1;
                } 
                else
                    r=mid-1;
            }
        }
        return -1;
    }
};
