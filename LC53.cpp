// Kadane's Algorithm ~ TC : O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int curr = 0;
        for(int val : nums) {
            curr += val;
            ans = max(ans, curr);
            if(curr < 0) curr = 0;
        }

        return ans;
    }
};