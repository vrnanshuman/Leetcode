class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int len = nums.size();
        vector<int> max_count(len,0);
        max_count[0] = nums[0];
        max_count[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<len;i++) {
            max_count[i] = max(max_count[i-1], max_count[i-2] + nums[i]);
        }
        return max_count[len-1];
        
    }
};
