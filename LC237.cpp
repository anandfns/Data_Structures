// TC : O(n)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* mover = node;
        ListNode* prev = nullptr;
        while(mover->next != nullptr) {
            mover->val = mover->next->val;
            prev = mover;
            mover = mover->next;
        }

        prev->next = nullptr;
        delete mover;
    }
};

// TC : O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};