class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        if(nums.size() == 1)
            return;
        int i,j,k,tmp;
        i=j=0, k=nums.size()-1;
        
        while(j<=k) {
            if(nums[j] == 1)
                j++;
            else if(nums[j] < 1) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j++;
            } else {
                tmp = nums[j];
                nums[j] = nums[k];
                nums[k] = tmp;
                k--;
            }
        }
    }
};