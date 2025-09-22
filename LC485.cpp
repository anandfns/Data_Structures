class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        for(int val : nums) {
            if(val == 1) curr++;
            else curr = 0;
            ans = max(curr, ans);
        }

        return ans;
    }
};