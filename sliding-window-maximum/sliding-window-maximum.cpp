class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_sliding_window;
        deque<int> q;
        
        int i,j;
        i=j=0;
        while(j<nums.size()) {
            
            while(!q.empty() && nums[j]>q.back()) {
                q.pop_back();     
            }
            q.push_back(nums[j]);

            if(j-i+1 == k) {
                max_sliding_window.emplace_back(q.front());
                if(nums[i] == q.front()) {
                    q.pop_front();
                }
                i++;
            }
            j++;
        }
        return max_sliding_window;
        
    }
};