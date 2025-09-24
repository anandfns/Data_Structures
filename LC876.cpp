// Most basic one ~ TC : O(N + N/2) and SC : O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while(temp != nullptr) { // TC : O(N)
            count++;
            temp = temp->next;
        }

        int nodeNum = count / 2;
        nodeNum++;

        temp = head;
        for(int i=1 ;i<nodeNum; i++) { // TC : O(N)
            temp = temp->next;
        }

        return temp;
    }
};

// Tortoise Hare / slow - fast pointer aprroach
// TC : O(N) ~ one pass and SC : O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
