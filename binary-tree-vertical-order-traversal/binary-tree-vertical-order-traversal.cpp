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
    
public:
    
    void traverse(TreeNode* root, int col, map<int, vector<int>> &nodeMap) {
        
        if(!root)
            return;
        queue<pair<int,TreeNode *>> q;
        q.push({0,root});
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            if(item.second->left)
                q.push({item.first-1, item.second->left});
            if(item.second->right)
                q.push({item.first+1, item.second->right});
            auto itr = nodeMap.find(item.first);
            if(itr != nodeMap.end()) {
                itr->second.emplace_back(item.second->val);
            } else {
                nodeMap.insert({item.first, {item.second->val}});
            }
        }
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> nodeMap;
        traverse(root, 0, nodeMap);
        
        vector<vector<int>> result;
        
        for(auto itr = nodeMap.begin(); itr!=nodeMap.end(); itr++) {
            result.emplace_back(itr->second);
        }
        return result;
    }
};