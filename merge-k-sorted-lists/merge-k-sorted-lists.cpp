/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct Node {
  bool operator < (const Node &that) const{
      return this->start->val > that.start->val;
  }
  Node(ListNode* that) {
      this->start = that;
  }
  ListNode* start;
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0)
            return nullptr;
        
        priority_queue<Node, vector<Node>> min_heap;
        for(auto list : lists) {
            if(list)
                min_heap.emplace(Node{list});
        }
        
        ListNode* merged = new ListNode();
        ListNode* tail = merged;
        while(!min_heap.empty()) {
            Node top = min_heap.top();
            tail->next = top.start;
            tail = tail->next;
            top.start = top.start->next;
            min_heap.pop();
            if(top.start)
                min_heap.emplace(top);
        }
        return merged->next;
    }
};