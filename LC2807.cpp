class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == nullptr) return head;
        ListNode* mover = head;
        while(mover->next != nullptr && mover != nullptr) {
            int GCD = gcd(mover->val, mover->next->val);
            ListNode* newNode = new ListNode(GCD, mover->next);
            mover->next = newNode;
            mover = mover->next->next;
        }
        return head;
    }
};