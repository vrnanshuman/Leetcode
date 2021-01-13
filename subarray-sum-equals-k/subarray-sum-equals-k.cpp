class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int,int> m;
        m.insert({0,1});
        int counter=0;
        int sum=0;int rem;
        for(int i=0;i<len;i++) {
            sum+=nums[i];
            rem = sum-k;
            auto itr = m.find(rem);
            if(itr!=m.end()) {
                counter+=itr->second;
            }
            itr = m.find(sum);
            if(itr!=m.end())
                itr->second++;
            else
                m.insert({sum,1});
            
        }
        
        return counter;
    }
};
