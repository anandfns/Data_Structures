// By Hashing TC : O(N) and SC : O(N)
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

// Tortoise Hare ~ TC : O(N) and SC : O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
    }
};