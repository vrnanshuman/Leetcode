/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void populateRight(Node* current, Node* parent) {
        if(!current)
            return;
        if(parent && parent->left == current) {
            current->next = parent->right;
        } else if(parent && parent->right == current) {
            if(parent->next)
                current->next = parent->next->left;
        }
        populateRight(current->left, current);
        populateRight(current->right, current);
    }
    
    Node* connect(Node* root) {
        populateRight(root, nullptr);
        return root;
    }
};