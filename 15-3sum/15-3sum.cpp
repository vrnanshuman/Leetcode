class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int a,b,c;
        int l,r,sum;
        sort(nums.begin(), nums.end());
        for(int i=0;i<=nums.size()-3;i++) {
            a = nums[i];
            
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            l = i+1;
            r = nums.size()-1;
            set<pair<int,int>> s;
            
            while(l<r) {
                
                sum = nums[l]+nums[r]+a;
                if(sum==0) {
                    auto itr = s.find({nums[l], nums[r]});
                    if(itr==s.end()) {
                        result.push_back({nums[i], nums[l], nums[r]});
                        s.insert({nums[l], nums[r]});
                    }
                    r--;
                } else if(sum > 0) {
                    r--;
                } else {
                    l++;
                }
                
            }
        }
        return result;
    }
};