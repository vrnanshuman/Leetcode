/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    queue<pair<TreeNode*, pair<int, int>>> Queue;
    
    static bool compare(const pair<int, int>& a, const pair<int,int>& b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
        
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> Map;
        
        vector<vector<int>> result;
        
        Queue.push(make_pair(root,make_pair(0,0)));
        
        int row, col, val;
        while(!Queue.empty()) {
            auto front = Queue.front();
            // cout<<front.first->val<<" Row: "<<front.second.first<< " Col "<< front.second.second<<endl;
            row = front.second.first;
            col = front.second.second;
            val = front.first->val;
            Queue.pop();
            
            auto itr = Map.find(col);
            if(itr!=Map.end()) {
                itr->second.push_back({val, row});
            } else {
                Map.insert({col, {make_pair(val, row)}});
            }
            if(front.first->left)
                Queue.push(make_pair(front.first->left,make_pair(row+1, col-1)));
            if(front.first->right)
                Queue.push(make_pair(front.first->right,make_pair(row+1, col+1)));
        }
        
        for(auto itr = Map.begin();itr!=Map.end();itr++) {
            sort(itr->second.begin(), itr->second.end(), compare);
            vector<int> tmp;
            for(auto p : itr->second) {
                tmp.emplace_back(p.first);
            }
            result.emplace_back(tmp);
        }
        return result;
    }
};