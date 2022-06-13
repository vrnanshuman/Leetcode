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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        TreeNode* front=nullptr;
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()) {
            front = q.front();
            q.pop();
            if(front) {
                level.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            } else{
                if(q.empty()){
                    result.push_back(level);
                    break;   
                } else {
                    result.push_back(level);
                    level.clear();
                    q.push(nullptr);
                }
            }
    
        }
        return result;
        
    }
};