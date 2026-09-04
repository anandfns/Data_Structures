class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mxArr(n, nums[0]);
        vector<int> mnArr(n, nums[n-1]);

        for(int i=1; i<n; i++) {
            mxArr[i] = max(mxArr[i-1], nums[i]);
            mnArr[n-1-i] = min(nums[n-1-i], mnArr[n-i]);
        }

        int ans = -1;
        for(int i=0; i<n; i++) {
            if(mxArr[i] - mnArr[i] <= k) {
                ans = i; break;
            }
        }

        return ans;
    }
};