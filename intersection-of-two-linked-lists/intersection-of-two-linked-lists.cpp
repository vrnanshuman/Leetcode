/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLength(ListNode *l) {
        int length = 0;
        while(l) {
            length++;
            l = l->next;
        }
        return length;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1 = headA;
        ListNode *h2 = headB;
        
        int l1 = getLength(headA);
        int l2 = getLength(headB);
        if(l1>l2) {
            for(int i=0;i<l1-l2;i++) {
                h1 = h1->next;
            }
        } else if (l2>l1) {
            for(int i=0;i<l2-l1;i++) {
                h2 = h2->next;
            }
        }
        while(h1 && h2) {
            if(h1 == h2) {
                return h1;
            }
            h1=h1->next;
            h2=h2->next;
        }
        return NULL;
    }
};
