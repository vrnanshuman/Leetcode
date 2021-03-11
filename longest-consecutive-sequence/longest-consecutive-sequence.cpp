class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <=1)
            return nums.size();
        unordered_map<int, bool> m;
        for(int i=0;i<nums.size();i++) {
            m.insert({nums[i], true});
        }
        
        unordered_map<int, bool>::iterator itr, itrl, itrr;
        int max_range = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            int range = 1;
            itr = m.find(nums[i]);
            if(itr==m.end() || itr->second == false)
                continue;
            int l = nums[i] - 1;
            while((itrl = m.find(l)) != m.end() && itrl->second==true) {
                range++;
                itrl->second = false;
                l -= 1;
            }
            int r = nums[i] + 1;
            while((itrr = m.find(r)) != m.end() && itrr->second==true) {
                range++;
                itrr->second = false;
                r += 1;
            }
            max_range = max(max_range, range);
        }
        return max_range;
    }
};