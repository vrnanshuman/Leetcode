class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1)
            return false;
        unordered_map<int, int> modMap;
        unordered_map<int, int>::iterator itr;
        modMap.insert({0, -1});
        int modk, curSum = 0;
        for(int i=0;i<nums.size();i++) {
            
            curSum += nums[i];
            // cout<<"CurSum "<<curSum<<endl;
            modk = curSum%k;
            // cout<<"ModK "<<modk<<endl;
            itr = modMap.find(modk);
            if(itr!=modMap.end()) {
                // cout<<"Searching"<<endl;
                // cout<<itr->second<<endl;
                // cout<<i<<endl;
                if(itr->second + 1 < i)
                    return true;
            } else {
                // cout<<"Inserting {"<<modk<<","<<i<<"}"<<endl;
                modMap.insert({modk, i});
            }
        }
        return false;
    }
};