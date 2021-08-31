class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int a,b,c;
        a = b = 0;
        
        vector<int> counts(10001, 0);
        int max_value = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int cc = count(nums.begin(), nums.end(), nums[i]);
            counts[nums[i]] = cc;
            max_value = max(max_value, nums[i]);
        }
        for(int i=1;i<=max_value;i++) {
            if(counts[i] > 0) {
               c = max(counts[i]*i + a, b); 
            } else {
                c = b;
            } 
            a = b;
            b = c;
        }
        return c;
    }
};