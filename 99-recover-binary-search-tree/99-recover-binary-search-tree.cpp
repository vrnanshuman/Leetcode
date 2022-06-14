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
    
    void findPrevGreaterThanCur(TreeNode* root, TreeNode* &prev, TreeNode* &result) {
        if(!root)
            return;
        findPrevGreaterThanCur(root->left, prev, result);
        if(result)
            return;
        if(prev && prev->val > root->val) {
            result = prev;
            return;
        }
        prev = root;
        findPrevGreaterThanCur(root->right, prev, result);
    }
    
    void findCurGreaterThanNext(TreeNode* root, TreeNode* &prev, TreeNode* &result) {
        if(!root)
            return;
        findCurGreaterThanNext(root->right, prev, result);
        if(result)
            return;
        if(prev && prev->val < root->val) {
            result = prev;
            return;
        }
        prev = root;
        findCurGreaterThanNext(root->left, prev, result);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* prev,*swap1, *swap2;
        int tmp;
        prev = swap1 = swap2 = nullptr;
        findPrevGreaterThanCur(root, prev, swap1);
        // cout<<swap1->val<<endl;
        prev=nullptr;
        findCurGreaterThanNext(root, prev, swap2);
        // cout<<swap2->val<<endl;
        tmp = swap1->val;
        swap1->val = swap2->val;
        swap2->val = tmp;
        
    }
};