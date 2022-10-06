/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    unordered_map<Node*, NodeCopy*> duplicatesMap;
public:
    
    NodeCopy* copyTree(Node* root1) {
        if(!root1)
            return nullptr;
        NodeCopy* root2 = new NodeCopy(root1->val);
        duplicatesMap.insert({root1, root2});
        root2->left = copyTree(root1->left);
        root2->right = copyTree(root1->right);
        return root2;
    }
    
    void populateRandom(Node* root1, NodeCopy* root2) {
        if(!root1)
            return;
        auto itr = duplicatesMap.find(root1->random);
        if(itr != duplicatesMap.end()) {
            root2->random = itr->second;
        }
        populateRandom(root1->left, root2->left);
        populateRandom(root1->right, root2->right);
        
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(!root)
            return nullptr;
        NodeCopy *root1 = copyTree(root);
        populateRandom(root, root1);
        return root1;
    }
};