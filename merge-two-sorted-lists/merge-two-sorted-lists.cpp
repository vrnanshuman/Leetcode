/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        ListNode *new_head, *new_tail;
        new_head = new_tail = NULL;
        
        while(l1 && l2) {
            if(l1->val < l2->val){
                if(!new_head) {
                    new_head = new_tail = l1;
                } else {
                    new_tail->next = l1;
                    new_tail = new_tail->next;
                }
                l1 = l1->next;
            } else {
                if(!new_head) {
                    new_head = new_tail = l2;
                } else {
                    new_tail->next = l2;
                    new_tail = new_tail->next;
                }
                l2 = l2->next;
            }
            
        }
        if(l1) {
            new_tail->next = l1;
        } else if(l2) {
            new_tail->next = l2;
        }
        return new_head;
    }
};
