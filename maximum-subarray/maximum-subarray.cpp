class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int running_sum = 0;
        
        for(int i=0;i<nums.size();i++) {
            running_sum = max(running_sum+nums[i], nums[i]);
            max_sum = max(max_sum, running_sum);
        }
        return max_sum;
    }
};