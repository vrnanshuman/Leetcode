class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_so_far = INT_MAX;
        int len = nums.size();
        int running_sum = 0;
        for(int i=0;i<len;i++) {
            running_sum += nums[i];
            min_so_far = min(min_so_far, running_sum);
        }
        if(min_so_far >= 0)
            return 1;
        return (1-min_so_far);
    }
};
