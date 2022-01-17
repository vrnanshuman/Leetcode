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
    
    void traverse(TreeNode* root, TreeNode* &prev, TreeNode* &head) {
        if(!root)
            return;
        TreeNode* tmp = root->right;
        if(!prev) {
            head = prev = root;
        } else {
            // cout<<"Prev "<<prev->val<<endl;
            prev->right = root;
            prev->left = nullptr;
        }
        
        // cout<<"Root "<<root->val<<endl;
        prev = root;
        traverse(root->left, prev, head);
        traverse(tmp, prev, head);
    }
    
    void flatten(TreeNode* root) {
        TreeNode* prev, *head;
        prev = head = nullptr;
        traverse(root, prev, head);
        root = head;
    }
};