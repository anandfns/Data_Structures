class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int val : nums) { // n ^ n = 0 and n ^ 0 = n
            ans = ans ^ val;
        }

        return ans;
    }
};