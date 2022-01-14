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
    int closestValue(TreeNode* root, double target) {
        double distance = abs((double)root->val - target);
        int result = root->val;
        double currentDistance = distance;
        
        while(root) {
            currentDistance = abs((double)root->val - target);
            
            if(currentDistance < distance) {
                distance = currentDistance;
                result = root->val;
            }
            if(target > root->val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return result;
        
    }
};