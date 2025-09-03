// Efficient one O(m + n) : m, n ~ lenghts
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* t3 = dummyNode;

        int carry = 0;
        while(t1 != nullptr || t2 != nullptr) {
            
            int sum = carry;
            if(t1) sum += t1->val;
            if(t2) sum += t2->val;

            // what happening above is
            // int first = 0;
            // int second = 0;

            // if(t1) first = t1->val;
            // if(t2) second = t2->val;

            // int sum = first + second + carry;

            ListNode* temp = new ListNode(sum%10);
            t3->next = temp;
            t3 = temp;

            carry = sum / 10;

            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }

        if(carry) {
            ListNode* temp = new ListNode(carry);
            t3->next = temp;
        }

        return dummyNode->next;
    }
};