class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return;
        for(int i=len-1;i>0;i--) {
            if(nums[i]>nums[i-1]){
                for(int j=len-1;j>=i;j--) {
                    if(nums[j]>nums[i-1]) {
                        int tmp = nums[i-1];
                        nums[i-1] = nums[j];
                        nums[j] = tmp;
                        reverse(nums.begin()+i, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};
