class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int prime = 30001;
        for(int i=0;i<n;i++) {
            int original_element = nums[i]%prime;
            int count = nums[original_element]/prime;
            
            if(count >=1)
                return original_element;
            nums[original_element] = (count+1)*prime + nums[original_element]%prime;
        }        
        return 0;
    }
};