class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return {nums[0]*nums[0]};
        
        int l,r, mid;
        l=0, r=len-1;
        int smallest = INT_MAX;
        int index = INT_MAX;
        while(l<=r) {
            mid = (l+r)/2;
            if(nums[mid] == 0) {
                smallest = 0;
                index = mid;
                break;
            } else if(nums[mid] < 0) {
                l=mid+1;
            }else {
                if(nums[mid]<smallest || (nums[mid]==smallest && mid<index)){
                    smallest = nums[mid];
                    index = mid;
                }
                r=mid-1;
            }
        }
        vector<int> result;
        if(index == INT_MAX) {
            l=len-2;
            r=len-1;
        } else {
            l=index-1;
            r=index;
        }
        while(l>=0 && r<len){
            auto sq_l = nums[l]*nums[l];
            auto sq_r = nums[r]*nums[r];
            if(sq_l<sq_r){
                result.emplace_back(sq_l);
                l--;
            }else{
                result.emplace_back(sq_r);
                r++;
            }
        }
        if(l>=0) {
            for(int i=l;i>=0;i--)
                result.emplace_back(nums[i]*nums[i]);
        }else {
            for(int i=r;i<len;i++)
                result.emplace_back(nums[i]*nums[i]);
        }
        return result;
    }
};