// using two pass
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


// Dummy Node Approach ~ TC : O(N);
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* start = dummy;

        for(int i=0; i<n; i++) {
            head = head->next;
        }

        while(head != nullptr) {
            head = head->next;
            dummy = dummy->next;
        }

        dummy->next = dummy->next->next;

        ListNode* ans = start->next;
        delete start;
        return ans;
    }
};