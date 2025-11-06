class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head == nullptr) return head;
        
        ListNode* mover = head;
        ListNode* prev = nullptr;

        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }

        while(mover != nullptr) {
            if(mover == head && s.find(mover->val) != s.end()) {
                head = head->next;
            } else if(s.find(mover->val) != s.end()) {
                prev->next = mover->next;
            }
            if(s.find(mover->val) == s.end()) prev = mover;
            mover = mover->next;
        }

        return head;
    }
};