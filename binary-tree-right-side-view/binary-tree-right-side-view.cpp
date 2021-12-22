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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> result;
        int flag = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()) {
            TreeNode* frontNode = q.front();
            q.pop();
            if(!frontNode) {
                if(q.empty())
                    break;
                flag = 1;
                q.push(nullptr);
            } else {
                if(flag){
                    result.emplace_back(frontNode->val);
                }
                flag = 0;
                if(frontNode->right)
                    q.push(frontNode->right);
                if(frontNode->left)
                    q.push(frontNode->left);
            }
        }
        return result;
    }
};