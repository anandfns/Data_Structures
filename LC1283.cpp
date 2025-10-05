class Solution {
public:
    bool check(vector<int>& nums, int t, int mid) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += ceil( (double)nums[i] / (double)mid );
        }
        return sum <= t;
    }

    int maxElem(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            ans = max(nums[i], ans);
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int t) {
        if(nums.size() > t) return -1;
        int low = 1;
        int high = maxElem(nums);
        // int ans = high;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if(check(nums, t, mid)) {
                // ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};