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
    
    int getDepth(Node* root) {
        int depth = 0;
        while(root){
            depth++;
            root = root->parent;
        }
        return depth;
    }
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int pDepth, qDepth;
        pDepth = getDepth(p);
        qDepth = getDepth(q);
        
        if(pDepth > qDepth) {
            swap(pDepth, qDepth);
            swap(p, q);
        }
        
        int skip = qDepth - pDepth;
        while(skip>0) {
            q = q->parent;
            skip--;
        }
        
        while(p!=q) {
            p = p->parent;
            q = q->parent;
        }
        return p;
        
    }
};