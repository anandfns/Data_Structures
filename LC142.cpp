class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* mover = head;
        unordered_set<ListNode*> s;

        while(mover != nullptr && s.find(mover) == s.end()) {
            s.insert(mover);
            mover = mover->next;
        }

        return mover;
    }
};