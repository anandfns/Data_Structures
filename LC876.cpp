// Most basic one

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int nodeNum = count / 2;
        nodeNum++;

        temp = head;
        for(int i=1 ;i<nodeNum; i++) {
            temp = temp->next;
        }

        return temp;
    }
};