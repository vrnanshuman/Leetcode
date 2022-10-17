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
    
    void helper(TreeNode* root, TreeNode* &prev) {
        if(!root)
            return;
        // cout<<root->val<<endl;
        if(prev)
            prev->right = root;
        TreeNode* right = root->right;
        prev = root;
        helper(root->left, prev);
        root->left = nullptr;
        helper(right, prev);
    }
    
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* tmp=nullptr;
        helper(root, tmp);
    }
};