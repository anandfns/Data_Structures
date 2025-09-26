// Basic Approach ~ TC : O(N + N/2) ~ Done in Two Pass
// SC : O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        int cnt = 0;
        ListNode* mover = head;
        while(mover != nullptr) {
            cnt++;
            mover = mover->next;
        }

        int n = cnt / 2;
        mover = head;
        while(n > 1) {
            mover = mover->next;
            n--;
        }

        mover->next = mover->next->next;
        return head;
    }
};

// Slow Fast Pointer Approach ~ TC : O(N) ~ Done in Single Pass
// SC : O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = slow;


        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        return head;
    }
};