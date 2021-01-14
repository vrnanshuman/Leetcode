class Solution {
public:
    int bsearch(int start, int end, int key, vector<int>& nums) {
        while(start <= end) {
            int mid = start+ (end-start)/2;
            if(key == nums[mid])
                return mid;
            else if(key<nums[mid])
                end = mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int to_search;
        int index;
        for(int i=0;i<len;i++){
            to_search = target - numbers[i];
            index = bsearch(i+1, len-1, to_search, numbers);
            if(index!=-1){
                return {i+1, index+1};
            }
        }
        return {};
    }
};
