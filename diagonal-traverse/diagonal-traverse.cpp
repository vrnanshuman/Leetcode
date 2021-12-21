class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> nMap;
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                auto itr = nMap.find(i+j);
                if(itr==nMap.end()) 
                    nMap.insert({i+j, {mat[i][j]}});
                else
                    itr->second.emplace_back(mat[i][j]);
            }
        }
        vector<int> result;
        int leftToRight = 1;
        for(auto itr=nMap.begin();itr!=nMap.end();itr++) {
            if(leftToRight == -1) {
                for(int num:itr->second)
                    result.emplace_back(num);
            } else {
                reverse(itr->second.begin(), itr->second.end());
                for(int num:itr->second)
                    result.emplace_back(num);
            }
            leftToRight *= -1;
        }
        return result;
        
    }
};