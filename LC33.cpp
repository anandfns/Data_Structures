class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        
        while(st <= end) {
            int mid = st + (end - end)/2;
            if(nums[mid] == target) return mid;

            if(nums[st] <= nums[mid]) { //left sorted
                if(nums[st] <= target && target <= nums[mid]) end = mid - 1; //if - in left sorted part - there is target present or not
                else st = mid + 1; // if not 
            } else {
                if(nums[mid] >= nums[end]) { //right sorted
                    if(nums[mid] <= target && target <= nums[end]) st = mid + 1; //if - in right sorted part - there is target present or not
                    else end = mid - 1; //if not
                }
            }
        }
    return -1;
    }
};