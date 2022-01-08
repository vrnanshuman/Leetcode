/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        auto itr = visited.find(head);
        if(itr!=visited.end())
            return itr->second;
        Node* tmp = new Node(head->val);
        visited.insert({head, tmp});
        tmp->random = copyRandomList(head->random);
        tmp->next = copyRandomList(head->next);
        return tmp;
    }
};