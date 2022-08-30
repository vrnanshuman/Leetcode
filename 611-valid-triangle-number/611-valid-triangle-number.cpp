class Solution {
public:
    
    int greaterThanK(vector<int>& nums, int l, int r,int& k) {
        int count = 0;
        
        while(l<r) {
            if(nums[l] + nums[r] > k){
                count+=r-l;
                r--;
            } else {
                l++;
            }
        }
        
        return count;
    }
    
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        int l,r;
        
        for(int i=nums.size()-1;i>=2;i--) {
            l = 0, r=i-1;
            count += greaterThanK(nums, l, r, nums[i]);
        }
        return count;
    }
};