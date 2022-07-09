class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long int> preSum(nums.size()+1, 0);
        int minSize = INT_MAX;
        for(int i=0;i<nums.size();i++)
            preSum[i+1] = preSum[i]+(long long int)nums[i];
        
        deque<int> dq;
        
        for(int i=0;i<preSum.size();i++) {
            while(!dq.empty() && preSum[i]-preSum[dq.front()] >=k ){
                minSize = min(minSize, i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && preSum[dq.back()]>=preSum[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return minSize == INT_MAX ? -1: minSize;
    }
};