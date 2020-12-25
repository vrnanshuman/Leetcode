class Solution {
    
    void helper(vector<int>& nums, int s, int index, int &len, int& count) {
        if(index == len) {
            if(s == 0)
                count++;
            return;
        }
        long long int sub = (long long int)s-nums[index];
        if(sub <= INT_MAX && sub >= INT_MIN)
            helper(nums, s-nums[index], index+1, len,count);
        long long int add = (long long int)s+nums[index];
        if(add <= INT_MAX && add >= INT_MIN)
            helper(nums, s+nums[index], index+1, len,count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        int len = nums.size();
        helper(nums, S, 0, len, count);
        return count;
    }
};
