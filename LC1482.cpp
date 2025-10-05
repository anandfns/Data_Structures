class Solution {
public:
    int maxElem(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            ans = max(nums[i], ans);
        }
        return ans;
    }

    int minElem(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            ans = min(nums[i], ans);
        }
        return ans;
    }

    // CRUX OF THE PROBLEM
    bool check(vector<int>& nums, int m, int k, int mid) {
        int totalBouq = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= mid) {
                count++;
            } else {
                totalBouq += count / k;
                if(totalBouq >= m) return true;
                count = 0;
            }
        }

        totalBouq += count / k;
        return totalBouq >= m;
    }

    int minDays(vector<int>& day, int m, int k) {
        long long val = 1LL * m * k;
        if(day.size() < val) return -1;

        int low = minElem(day);
        int high = maxElem(day);
        int ans = high;

        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(check(day, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};