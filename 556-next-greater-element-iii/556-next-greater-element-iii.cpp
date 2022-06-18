class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        int number = n;
        while(number>0) {
            nums.push_back(number%10);
            number /= 10;
        }
        reverse(nums.begin(), nums.end());
        int idx = nums.size()-1;
        while(idx>0) {
            if(nums[idx] > nums[idx-1])
                break;
            idx--;
        }
        if(idx==0)
            return -1;
        int key = nums[idx-1];
        int pos = idx-1;
        while(idx<nums.size() && key<nums[idx]) {
            idx++;
        }
        int tmp = nums[idx-1];
        nums[idx-1] = key;
        nums[pos] = tmp;
        reverse(nums.begin()+pos+1, nums.end());
        long nextPerm = 0;
        for(int i=0;i<nums.size();i++){
            nextPerm = nextPerm*10 + nums[i];
        }
        if(nextPerm > INT_MAX)
            return -1;
        return (int)nextPerm;
    }
};