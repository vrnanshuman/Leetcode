class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if(len<=1)
            return false;
        map<int,int> m;
        m.insert({0,-1});
        int sum = 0;
        for(int i=0;i<len;i++) {
            sum += nums[i];
            if(k != 0) {
                sum %= k;
            }
            auto itr = m.find(sum);
            if(itr != m.end()) {
                if(i - itr->second >= 2) {
                    return true;
                }
            } else {
                m.insert({sum,i});
            }
        }
        return false;
    }
};
