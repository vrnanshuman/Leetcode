class Solution {
public:
    
    int bsearch(vector<int> &nums, int &val) {
        int len = nums.size();
        int smallest = INT_MAX;
        int l,r, mid;
        l=0, r=len-1;
        while(l<=r) {
            mid = (l+r)/2;
            if(nums[mid] == val)
                return val;
            else if(nums[mid] < val) {
                smallest = nums[mid];
                l = mid+1;
            } else {
                r = mid -1;
            }
        }
        return smallest;
    }
    
    string intToRoman(int num) {
        unordered_map<int, string> m = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        vector<int> values = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string roman = "";
        while(num>0) {
            int smallest = bsearch(values, num);
            auto itr = m.find(smallest);
            roman += itr->second;
            num = num - smallest;
        }
        return roman;
    }
};