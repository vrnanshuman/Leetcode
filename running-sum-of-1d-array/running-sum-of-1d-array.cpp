class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return {};
        vector<int> running(len, 0);
        running[0] = nums[0];
        
        for(int i=1;i<len;i++)
            running[i] = nums[i] + running[i-1];
        return running;
        
    }
};
