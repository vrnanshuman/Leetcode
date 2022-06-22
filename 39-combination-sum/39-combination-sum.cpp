class Solution {
public:
    void generate(vector<int>& candidates, int target, vector<vector<int>> &results, vector<int> current, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            results.emplace_back(current);
            return;
        }
        
        for(int i=idx; i<candidates.size();i++) {
            current.push_back(candidates[i]);
            generate(candidates, target-candidates[i], results, current, i);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        generate(candidates, target, results, {},0);
        return results;
    }
};