class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l,r,sum;
        vector<int> result(2,-1);
        l=0, r=numbers.size()-1;
        while(l<r) {
            sum = numbers[l] + numbers[r];
            if(sum == target)
                return {l+1, r+1};
            else if(sum < target) 
                l++;
            else
                r--;
        }
        return {};
    }
};