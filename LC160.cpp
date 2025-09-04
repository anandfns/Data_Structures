// SC : O(m + n) ~ we are storing all the nodes in set
// TC : O(m + n) ~ Even though the loop runs max(m, n) times, the standard way to state it is O(m+n) because both lists are fully traversed. 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != nullptr || t2 != nullptr) {
            if(s.find(t1) != s.end()) {
                if(t1 != nullptr) return t1;
            } else {
                s.insert(t1);
                if(t1) t1 = t1->next;
            }

            if(s.find(t2) != s.end()) {
                if(t2 != nullptr) return t2;
            } else {
                s.insert(t2);
                if(t2) t2 = t2->next;
            }
        }

        return nullptr;
    }
};