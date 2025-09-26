// Using Extra Space ~ TC : O(2N + NlogN) and SC : O(N)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        vector<int> vec;
        ListNode* mover = head;

        while(mover != nullptr) {
            vec.push_back(mover->val);
            mover = mover->next;
        }

        sort(vec.begin(), vec.end());

        int i = 0;
        mover = head;
        while(mover != nullptr) {
            mover->val = vec[i];
            i++;
            mover = mover->next;
        }

        return head;
    }
};

