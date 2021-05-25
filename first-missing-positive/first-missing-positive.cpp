class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        if(nums.size() == 1) {
            if(nums[0] == 1)
                return 2;
            return 1;
        }
        
        auto itr = find(nums.begin(), nums.end(), 1);
        if(itr==nums.end())
            return 1;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] <= 0 || nums[i] > nums.size()){
                nums[i] = 1;
            }   
        }
        
        for(int i=0;i<nums.size();i++) {
            int index = abs(nums[i])%nums.size();
            if(nums[index] > 0) {
                nums[index] *= -1;
            }
        }
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i] > 0)
                return i;
        }
        if(nums[0] > 0)
            return nums.size();
        return nums.size()+1;
    }
};