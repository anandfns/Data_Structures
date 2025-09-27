class Solution {
public:
    int second(vector<int>& nums , int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int first(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int a = first(nums, target);
        // if the first occurence is not there, then there is no gain in searching for second, we can return then and there
        if(a == -1) return {-1 , -1};
        int b = second(nums, target);
        return {a, b};
    }
};