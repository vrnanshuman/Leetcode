class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd, minProd, result, tmp;
        maxProd = minProd = result = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            tmp = maxProd;
            maxProd = max(nums[i], max(minProd *nums[i], maxProd * nums[i]));
            minProd = min(nums[i], min(minProd *nums[i], tmp * nums[i]));
            result = max(result, maxProd);
        }
        return result;
        
    }
};