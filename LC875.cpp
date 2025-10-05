class Solution {
public:
    int maxElem(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            ans = max(nums[i], ans);
        }
        return ans;
    }

    bool check(vector<int>& nums, int h, int mid) {
        long long sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += ceil((double)nums[i] / (double)mid);
        }
        return sum <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElem(piles);
        int ans = high;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(check(piles, h, mid)) {
                // ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // return ans;
        return low;
    }
};