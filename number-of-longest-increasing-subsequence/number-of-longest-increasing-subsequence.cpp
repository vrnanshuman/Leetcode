class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return 1;
        vector<int> dp_lis(len, 1);
        vector<int> dp_nums(len, 0);
        
        for(int i=1;i<len;i++) {
            int max_sub = 0;
            for(int j=0;j<i;j++) {
                if(nums[i] > nums[j]) {
                    max_sub = max(max_sub, dp_lis[j]);
                }
            }
            dp_lis[i] = 1 + max_sub;
        }
        dp_nums[0] = 1;
        for(int i=1;i<len;i++) {
            if(dp_lis[i] == 1)
                dp_nums[i] = 1;
            else {
                for(int j=0;j<i;j++) {
                    if(nums[j] < nums[i] && dp_lis[j]+1 == dp_lis[i]) {
                        dp_nums[i] += dp_nums[j]; 
                    }       
                }
            }
        }
        int max_lis = *max_element(dp_lis.begin(), dp_lis.end());
        int count = 0;
        for(int i=0;i<len;i++) {
            if(dp_lis[i] == max_lis)
                count += dp_nums[i];
        }
        return count;
    }
};