class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        map<int,int> m;
        for(int i=0;i<len;i++) {
            auto itr = m.find(nums[i]);
            if(itr!=m.end()) {
                if(i-itr->second <= k)
                    return true;
                itr->second = i;
            }
            m.insert({nums[i], i});
        }
        return false;
    }
};
