// TC : O(N) and SC : O(1)
// Not Much cleaner
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* temp = even;
        ListNode* prev = odd;

        while(odd != nullptr && even != nullptr) {
            prev = odd;

            odd->next = even->next;
            odd = even->next;

            if(odd != nullptr) {
            even->next = odd->next;
            even = odd->next;
            }
            
        }

        if(odd != nullptr) odd->next = temp;
        else prev->next = temp;

        return head;
    }
};