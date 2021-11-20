class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for(int i=0;i<nums.size();i++) {
            auto itr = s.find(nums[i]);
            if(itr!=s.end())
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};