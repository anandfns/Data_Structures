// By Hashing
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;

        ListNode* temp = head;
        while(s.find(temp) == s.end() && temp != nullptr) {
            s.insert(temp);
            temp = temp->next;
        }

        if(temp != nullptr) return true;
        else return false;
    }
};