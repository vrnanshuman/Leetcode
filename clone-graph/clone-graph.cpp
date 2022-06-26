/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        Node* cpy = new Node(node->val);
        m.insert({node->val, cpy});
        for(Node* neighbor : node->neighbors) {
            auto itr = m.find(neighbor->val);
            if(itr!=m.end()) {
                cpy->neighbors.push_back(itr->second);
            } else {
                Node* cloned = cloneGraph(neighbor);
                cpy->neighbors.push_back(cloned);
            }
        }
        return cpy;
    }
};