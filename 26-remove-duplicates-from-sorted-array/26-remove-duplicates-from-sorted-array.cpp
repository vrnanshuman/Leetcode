class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        int i;
        i=1;
    
        for(int j=1;j<nums.size();) {
            if(nums[j]  == nums[j-1]) {
                j++;
            } else {
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        return i;
    }
};