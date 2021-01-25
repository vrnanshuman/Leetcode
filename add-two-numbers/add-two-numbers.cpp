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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry;
        carry = 0;
        int val1, val2;
        ListNode *cur, *result;
        result = new ListNode();
        cur = result;
        while(l1 || l2) {
            val1 = l1 == NULL ? 0: l1->val;
            val2 = l2 == NULL ? 0: l2->val;
            sum = val1 + val2 + carry;
            carry = sum/10;
            sum = sum%10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(carry != 0){
            cur->next = new ListNode(carry);
        }
        return result->next;
    }
};
