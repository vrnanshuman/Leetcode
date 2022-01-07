/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    pair<int, TreeNode*> LCAHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return {0, nullptr};
        pair<int, TreeNode*> left = LCAHelper(root->left, p, q);
        if(left.first == 2)
            return left;
        pair<int, TreeNode*> right = LCAHelper(root->right, p, q);
        if(right.first == 2)
            return right;
        int check = left.first+ right.first + (root == p) + (root == q);
        return check == 2 ? make_pair(check, root) : make_pair(check, nullptr);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCAHelper(root, p, q).second;
    }
};