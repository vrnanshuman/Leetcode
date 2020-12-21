class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        
        int max_so_far = nums[0], min_so_far = nums[0], result = nums[0];
        for(int i=1;i<len;i++) {
            int max_tmp = max(nums[i], max(nums[i]* max_so_far, nums[i]*min_so_far));
            int min_tmp = min(nums[i], min(nums[i]*min_so_far, nums[i]*max_so_far));
            max_so_far = max_tmp;
            min_so_far = min_tmp;
            result = max(max_so_far, result);
        }
        return result;
    }
};
