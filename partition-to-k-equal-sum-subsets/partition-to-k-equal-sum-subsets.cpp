class Solution {
public:
    
    bool validate(vector<int> &nums, int index, int current_sum, int target_sum, int k, vector<bool> &used) {
        if(k==1)
            return true;
        if(current_sum > target_sum) {
            return false;
        }
        if(current_sum == target_sum) {
            return validate(nums, 0, 0, target_sum, k-1, used);
        }
        for(int i=index;i<nums.size();i++) {
            if(!used[i]) {
                used[i] = true;
                if(validate(nums, index+1, current_sum + nums[i], target_sum, k, used))
                    return true;
                used[i] = false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(k==0 || (sum%k != 0))
            return false;
        vector<bool> used(nums.size(), false);
        int target_sum = sum/k;
        return validate(nums, 0, 0, target_sum, k, used);
    }
};