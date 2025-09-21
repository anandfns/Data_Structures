// Moore's voting algorithm ~ TC : O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = 0;
        int freq = 0;  
        for(int i=0; i<nums.size(); i++) {
            if(freq == 0) curr = nums[i];
            if(curr = nums[i]) freq++;
            else freq--;
        }

        return curr;
    }
};