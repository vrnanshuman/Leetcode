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
    
    void inorder(TreeNode* root, vector<int> &traversal) {
        if(root) {
            inorder(root->left, traversal);
            traversal.emplace_back(root->val);
            inorder(root->right, traversal);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        inorder(root, traversal);
        return traversal;
    }
};