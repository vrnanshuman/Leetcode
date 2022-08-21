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
    
    void getSum(TreeNode* root, TreeNode* parent, int& sum) {
        if(!root)
            return;
        getSum(root->left, root, sum);
        if(!root->left && !root->right && parent && parent->left==root)
            sum+=root->val;
        getSum(root->right, root, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        getSum(root, nullptr, sum);
        return sum;
    }
};