class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> idx;
        stack<int> s;
        for(int i=heights.size()-1;i>=0;i--) {
            while(!s.empty() && s.top() < heights[i])
                s.pop();
            if(s.empty()) {
                idx.emplace_back(i);
            }
            s.push(heights[i]);
        }
        reverse(idx.begin(), idx.end());
        return idx;
    }
};