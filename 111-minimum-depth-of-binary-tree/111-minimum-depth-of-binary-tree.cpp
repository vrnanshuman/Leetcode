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
    
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode* front=nullptr;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int minDepth = 1;
        
        while(!q.empty()) {
            front = q.front();
            q.pop();
            if(front && isLeaf(front))
                return minDepth;
            if(front) {
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            } else{
                if(q.empty()){
                    break;   
                } else {
                    q.push(nullptr);
                    minDepth++;
                }
            }
    
        }
        return minDepth;
    }
};