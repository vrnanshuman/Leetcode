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
    
    TreeNode* findRightMost(TreeNode* root) {
        while(root->right)
            root = root->right;
        return root;
    }
    
    TreeNode* deleteRoot(TreeNode* root) {
        if(!root->left)
            return root->right;
        if(!root->right)
            return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* rightMost = findRightMost(root->left);
        rightMost->right = rightChild;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val == key)
            return deleteRoot(root);
        TreeNode *prev,*curr;
        prev = nullptr;
        curr = root;
        
        while(curr) {
            if(curr->val == key)
                break;
            else if(curr->val < key) {
                prev = curr;
                curr = curr->right;
            } else {
                prev = curr;
                curr = curr->left;   
            }
        }
        if(!curr)
            return root;
        if(prev->left == curr)
            prev->left = deleteRoot(curr);
        else
            prev->right = deleteRoot(curr);
        return root;
    }
};