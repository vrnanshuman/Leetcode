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
    struct Quad {
      int size;
      bool isBST;
      int min;
      int max;
    };
public:
    
    Quad traverse(TreeNode* root) {
        if(!root)
            return Quad{0,true, INT_MAX, INT_MIN};
        Quad left = traverse(root->left);
        Quad right = traverse(root->right);
        if(left.isBST && right.isBST && left.max<root->val && root->val < right.min) {
            int lmin = left.min == INT_MAX ? root->val : left.min;
            int rmax = right.max == INT_MIN ? root->val : right.max;
            return Quad{1+left.size+right.size, true, lmin, rmax};
        }
        int size = left.size>right.size?left.size:right.size;
        return Quad{size, false, left.min, right.max};
    }
    
    int largestBSTSubtree(TreeNode* root) {
        return traverse(root).size;
    }
};