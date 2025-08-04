class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        if(n == 1) return nums[0];
        while(st <= end) {
            int mid = st + (end - st)/2;
            
            if(mid == 0 && nums[mid] != nums[mid+1]) return nums[mid]; // nums[0] != nums[1] , we should use this for better clarity
            if(mid == n - 1 && nums[mid-1] != nums[mid]) return nums[mid]; //nums[n - 1] != nums[n - 2]

            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) return nums[mid];

            if(mid % 2 == 0) { // if mid is even then the number of elements to the left nad right of mid will be even
                if(nums[mid - 1] == nums[mid]) end = mid - 1;
                else st = mid + 1;
            } else { // number of element to the left and right of mid - odd
                if(nums[mid - 1] == nums[mid]) st = mid + 1;
                else end = mid - 1;
            }
        }
    return -1;
    }
};