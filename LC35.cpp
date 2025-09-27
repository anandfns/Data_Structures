// Search Insert Position ~ Lower Bound
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

// other solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        int mid;
        bool val;
        while(st <= end){
            mid = st + (end - st)/2;
            val = false;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid - 1;
            else st = mid + 1;
        }

        if(!val){
            if(nums[mid] > target) {
                if(mid == 0) return 0;
                else return mid;
            }
            else return mid + 1;
        }

        return -1;
    }
};