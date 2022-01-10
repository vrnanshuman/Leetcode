/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    
    void convert(Node* root, Node* &head, Node* &prev) {
        if(!root)
            return;
        convert(root->left, head, prev);
        if(prev == nullptr) {
            head = root;
            prev = root;
        } else {
            root->left = prev;
            prev->right = root;
            prev = root;
        }
        convert(root->right, head, prev);
    }
    
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        Node* head, *prev;
        head = prev = nullptr;
        convert(root, head, prev);
        head->left = prev;
        prev->right = head;
        return head;
    }
};