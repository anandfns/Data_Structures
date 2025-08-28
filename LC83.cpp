// Basic approach

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        while(head->next != nullptr && head->val == head->next->val) {
            ListNode* del = head;
            head = head->next;
            delete del;
        }

        if(head->next == nullptr) return head;

        ListNode* mover = head;
        ListNode* prev = nullptr;
        while(mover->next != nullptr) {
            if(mover->val == mover->next->val) {
                prev->next = mover->next;
                ListNode* del = mover;
                mover = mover->next;
                delete del;
            } else {
                prev  = mover;
                mover = mover->next;
            }
        }

        return head;
    }
};