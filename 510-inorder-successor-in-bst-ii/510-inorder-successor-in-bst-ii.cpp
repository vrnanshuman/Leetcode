/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node *current, *parent;
        
        if(node->right) {
            current = node->right;
            while(current->left)
                current = current->left;
            return current;
        }
        if(!node->parent)
            return nullptr;
        parent = node->parent;
        current = node;
        
        if(current == parent->left)
            return parent;
        while(parent && current!=parent->left){
            current = parent;
            parent = current->parent;
        }
        return parent;
    }
};