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
    
    void populateRight(Node* leftmost) {
        if(!leftmost)
            return;
        Node* curr = leftmost;
        Node* newLeftmost = nullptr;
        Node* prev = nullptr;
        while(curr) {
            if(curr->left) {
                if(prev) {
                    prev->next = curr->left;
                    prev = curr->left;
                } else {
                    newLeftmost = prev = curr->left;
                }
            }
            if(curr->right) {
                if(prev) {
                    prev->next = curr->right;
                    prev = curr->right;
                } else {
                    newLeftmost = prev = curr->right; 
                }
            }
            curr = curr->next;
        }
        populateRight(newLeftmost);
    }
    
    Node* connect(Node* root) {
        populateRight(root);
        return root;
    }
};