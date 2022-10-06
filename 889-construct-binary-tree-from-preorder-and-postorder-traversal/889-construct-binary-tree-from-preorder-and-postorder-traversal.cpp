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
    struct IdxRange {
        int start;
        int end;
    };
    vector<int> pre,post;
    unordered_map<int,int> postPos;
public:
    
    TreeNode* construct(IdxRange preIdx, IdxRange postIdx) {
        // cout<<"Root "<<pre[preIdx.start]<<endl;
        // cout<<"PreIdx "<<preIdx.start<<","<<preIdx.end<<endl;
        // cout<<"PostIdx "<<postIdx.start<<","<<postIdx.end<<endl<<endl;
        if(preIdx.end < preIdx.start)
            return nullptr;
        TreeNode* root = new TreeNode(pre[preIdx.start]);
        if(preIdx.start == preIdx.end)
            return root;
        int preElement = pre[preIdx.start+1];
        int posInPost = postPos[preElement];
        int postOffset = posInPost-postIdx.start;
        
        root->left = construct(IdxRange{preIdx.start+1, preIdx.start+1+postOffset},IdxRange{postIdx.start, posInPost});
        root->right = construct(IdxRange{preIdx.start+1+postOffset+1, preIdx.end},IdxRange{posInPost+1, postIdx.end-1});
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        pre = preorder;
        post = postorder;
        int len = preorder.size();
        
        for(int i=0;i<postorder.size();i++) {
            postPos.insert({postorder[i],i});
        }
        
        return construct(IdxRange{0,len-1}, IdxRange{0, len-1});
    }
};