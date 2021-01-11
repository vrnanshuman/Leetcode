class Solution {
public:
    static bool comp(const vector<int>&a , const vector<int>&b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int len = intervals.size();
        if(len == 0)
            return {};
        if(len == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        merged.emplace_back(intervals[0]);
        int current = 0;
        for(int i=1;i<len;i++) {
           if(intervals[i][0] <= merged[current][1]){
               merged[current][1] = max(intervals[i][1], merged[current][1]);
           } else{
               merged.emplace_back(intervals[i]);
               current++;
           }
        }
        return merged;
    }
};
