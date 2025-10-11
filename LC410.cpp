// Based on Book Allocation / Painter's Partition Algorithm
// Using Binary search ~ TC : O(log(sum - max + 1) * n)
// Using Linear search ~ TC : O((sum-max+1) * n)
class Solution {
public:
    bool check(vector<int>& nums, int mid, int k) {
        int cnt = 1, val = 0;
        for(int i=0; i<nums.size(); i++) {
            if(val + nums[i] <= mid) val += nums[i];
            else {
                cnt++;
                val = nums[i];
            }
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int i=0; i<nums.size(); i++) {
            high += nums[i];
        }

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(check(nums, mid, k)) high = mid - 1;
            else low = mid + 1;
        }
        return low;

        // for(int i=low; i<= high; i++) {
        //     if(check(nums, i, k)) return i;
        // }
        // return -1;
    }
};