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
    
    void getInorder(TreeNode* root, vector<TreeNode*>& inorder) {
        if(!root)
            return;
        getInorder(root->left, inorder);
        inorder.emplace_back(root);
        getInorder(root->right, inorder);
    }
    
    TreeNode* getBalanced(vector<TreeNode*> &inorder,int l, int r) {
        if(l>r)
            return nullptr;
        int mid = l + (r-l)/2;
        inorder[mid]->left = getBalanced(inorder, l, mid-1);
        inorder[mid]->right = getBalanced(inorder, mid+1, r);
        return inorder[mid];
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)
            return nullptr;
        vector<TreeNode*> inorder;
        getInorder(root, inorder);
        return getBalanced(inorder, 0, inorder.size()-1);
        
    }
};