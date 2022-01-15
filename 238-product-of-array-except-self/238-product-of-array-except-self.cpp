class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(nums), right(nums);
        
        for(int i=1;i<len;i++) {
            left[i] = left[i-1]*nums[i];
        }
        
        for(int i=len-2;i>=0;i--) {
            right[i] = right[i+1]*nums[i];
        }
        
        vector<int> result(len, 1);
        
        for(int i=0;i<len;i++) {
            result[i] = i-1 >= 0 ? left[i-1] :1;
            result[i] *= i+1 < len ? right[i+1] : 1;
        }
        return result;
    }
};