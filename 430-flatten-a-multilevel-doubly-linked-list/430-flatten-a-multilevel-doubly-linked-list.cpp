/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    pair<Node*,Node*> flatten2(Node* head) {
        if(!head)
            return {nullptr, nullptr};
        Node *curr, *tail, *prev, *next;
        curr = head;
        prev = nullptr;
        while(curr) {
            if(curr->child) {
                pair<Node*,Node*> p = flatten2(curr->child);
                if(curr->next) {
                    next = curr->next;
                    curr->next = p.first;
                    p.first->prev = curr;
                    p.second->next = next;
                    next->prev = p.second;
                } else {
                    curr->next = p.first;
                    p.first->prev = curr;
                }
                curr->child = nullptr;
            }
            prev = curr;
            curr=curr->next;
        }
        tail = prev;
        return {head, tail};
    }
    
    Node* flatten(Node* head) {
        return flatten2(head).first;
    }
};