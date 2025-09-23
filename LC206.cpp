// Basic one
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;
        ListNode* front = curr->next;
        ListNode* back = nullptr;

        while(curr != nullptr) {
            curr->next = back;
            back = curr;
            curr = front;
            if(front != nullptr) front = front->next; // if we dont do the check here, we will get segmentation fault(invalid mempry access)
        }

        return back;
    }
};

// Recursive approach ~ TC : O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // or we can make a helper function to do the same by passing only head
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};