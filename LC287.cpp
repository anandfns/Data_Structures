//*****************Unordered Set approach***************

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(s.find(nums[i]) != s.end()){
                return nums[i];
            }
            s.insert(nums[i]);
        }

        return -1;
    }
};


//*************Slow Fast Approach****************

class Solution {
public:
    int findDuplicate(vector<int>& nums) {        

        int slow = nums[0] , fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while ( slow != fast );

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};