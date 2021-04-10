class Solution {
public:
    
    struct NumCount {
        int num;
        int count;
        
        bool operator < (const NumCount& that) const {
            return count > that.count;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<NumCount, vector<NumCount>> min_heap;
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++) {
            auto itr = m.find(nums[i]);
            if(itr!=m.end()) {
                itr->second++;
            } else {
                m.insert({nums[i], 1});
            }
        }
        int count = 0;
        for(auto itr = m.begin();itr!=m.end(); ++itr) {
            if(count < k)
                min_heap.emplace(NumCount{itr->first, itr->second});
            else {
                if(itr->second > min_heap.top().count) {
                    min_heap.pop();
                    min_heap.emplace(NumCount{itr->first, itr->second});
                }
            }
            count++;
        }
        vector<int> kMostFrequent;
        while(!min_heap.empty()) {
            kMostFrequent.emplace_back(min_heap.top().num);
            min_heap.pop();
        }
        
        return kMostFrequent;
    }
};