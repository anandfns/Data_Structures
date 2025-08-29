// Most straight forward way
// make a new linked list, then add the Nodes in increasing fashion of their values
// TC : O(m+n) because we are traversing on each element
// SC : O(m+n) because of that del Node - safe from memory leak but uses extra space
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        

        ListNode* head = new ListNode(0);
        ListNode* back = head;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val > list2->val) {
                ListNode* temp = new ListNode(list2->val);
                back->next = temp;
                back = temp;
                
                ListNode* del = list2;
                list2 = list2->next;
                delete del;

            } else if(list1->val < list2->val) {
                ListNode* temp = new ListNode(list1->val);
                back->next = temp;
                back = temp;

                ListNode* del = list1;
                list1 = list1->next;
                delete del;
            } else {
                ListNode* temp1 = new ListNode(list1->val);
                back->next = temp1;
                back = temp1;

                ListNode* del1 = list1;
                list1 = list1->next;
                delete del1;

                ListNode* temp2 = new ListNode(list2->val);
                back->next = temp2;
                back = temp2;

                ListNode* del2 = list2;
                list2 = list2->next;
                delete del2;

            }
        }

        //what if dono me se koi ek bacha reh gya
        // if list1 == nullptr -> list1 != nullptr
        if(list1 != nullptr) {
            while(list1 != nullptr) {
                ListNode* temp = new ListNode(list1->val);
                back->next = temp;
                back = temp;

                ListNode* del = list1;
                list1 = list1->next;
                delete del;
            } 
        } else {
            while(list2 != nullptr) {
                ListNode* temp = new ListNode(list2->val);
                back->next = temp;
                back = temp;

                ListNode* del = list2;
                list2 = list2->next;
                delete del;
            } 
        }

        ListNode* del = head;
        head = head->next;
        delete del;
        return head;
        
    }
};