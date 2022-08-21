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
    
    void traverse(TreeNode* root, vector<string>& paths ,string path) {
        if(!root)
            return;
        if(path.empty())
            path+=to_string(root->val);
        else{
            path+="->";
            path+=to_string(root->val);
        }
        
        if(!root->left && !root->right) {
            paths.emplace_back(path);
        } else {
            traverse(root->left, paths, path);
            traverse(root->right, paths, path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        traverse(root, paths, "");
        return paths;
    }
};