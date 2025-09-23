// By using vector ~ TC : O(N) and SC : O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return false;

        vector<int> vec;
        ListNode* mover = head;

        while(mover != nullptr) {
            vec.push_back(mover->val);
            mover = mover->next;
        }

        int i = 0;
        int j = vec.size()-1;

        while(i <= j) {
            if(vec[i] != vec[j]) return false;
            i++; j--;
        }

        return true;
    }
};

// By using stack ~ TC : O(N) and SC :(N/2)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return false;

        stack<int> s;
        ListNode* mover = head;

        int node = 0;
        while(mover != nullptr) {
            node++;
            mover = mover->next;
        }

        mover = head;
        for(int i=0; i<node/2; i++) {
            s.push(mover->val);
            mover = mover->next;
        }

        if(node % 2 != 0) mover = mover->next; // if the linked list is of odd number of nodes then we will skip the middle element

        for(int i=0; i<node/2; i++) {
            if(s.top() == mover->val) s.pop();
            mover = mover->next;
        }

        return s.empty();
    }
};