class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int maxElem = *max_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            ans += maxElem - nums[i];
        }
        return ans;
    }
};