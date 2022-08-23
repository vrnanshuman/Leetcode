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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        int maxValue = INT_MIN;
        TreeNode* front;
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()) {
            front = q.front();
            q.pop();
            if(front) {
                maxValue = max(maxValue, front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            } else {
                result.emplace_back(maxValue);
                maxValue = INT_MIN;
                if(q.empty())
                    return result;
                else
                    q.push(nullptr);
            }
        }
        return result;
    }
};