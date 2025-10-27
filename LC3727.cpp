// TC : O(NlogN)
// take abs -> sort it -> if array length -> (ODD - we will len/2 + 1 greatest element of nums) 
// or (EVEN - add len/2 greatest ans) -> return the ans

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());

        long long ans = 0;
        int val = nums.size()/2;
        if(nums.size() & 1) val++;

        int idx = nums.size() - 1;
        while(idx >= 0) {
            if(val != 0) {
                ans += (1LL * nums[idx] * nums[idx]);
                val--;
            }
            else ans -= (1LL * nums[idx] * nums[idx]);
            idx--; 
        }

        return ans;
    }
};