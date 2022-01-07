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
    
    pair<int, bool> checkBalance(TreeNode* root) {
        if(!root)
            return {-1, true};
        int leftHeight;
        bool isLeftBalanced;
        tie(leftHeight, isLeftBalanced) = checkBalance(root->left);
        if(!isLeftBalanced)
            return {-1, false};
        int rightHeight;
        bool isRightBalanced;
        tie(rightHeight, isRightBalanced) = checkBalance(root->right);
        if(!isRightBalanced)
            return {-1, false};
        return {1+max(leftHeight, rightHeight), abs(leftHeight-rightHeight) <= 1};
    }
    
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).second;
    }
};