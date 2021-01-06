class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if(len < 3)
            return -1;
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        
        for(int i=1;i<len;i++)
            left[i] = left[i-1] + nums[i-1];
        for(int i=len-2;i>=0;i--)
            right[i] = right[i+1] + nums[i+1];
        for(int i=0;i<len;i++) {
            if(left[i] == right[i])
                return i;
        }
        return -1;
    }
};
