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
    void traverse(TreeNode* root, int &prev, int& minDiff) {
        if(!root)
            return;
        traverse(root->left, prev,minDiff);
        if(prev!=-1){
            minDiff = min(minDiff, abs(root->val-prev));
        }
        prev = root->val;
        traverse(root->right, prev,minDiff);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        traverse(root, prev, minDiff);
        return minDiff;
    }
};