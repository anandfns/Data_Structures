// using two pass ~ can solve this by one pass by using slow fast pointer
// TC : O(N) and SC : O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* mover = head;
        
        int count = 0;

        while(mover != nullptr) { // To count the total number of nodes
            count++;
            mover = mover->next;
        }

        // edge case
        if(n == count) {
            if(head->next == nullptr) return nullptr;
            else return head->next;
        }

        mover = head;
        for(int i=1; i<count-n; i++) { // nth from last == after (count-n) from start
            mover = mover->next;
        }

        mover->next = mover->next->next;

        return head;
    }
};