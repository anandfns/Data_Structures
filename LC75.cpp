class Solution {
public:
    void sortColors(vector<int>& nums) {

        //**********************Beginner's Method*************************
        int n = nums.size();
        int zero = 0, one = 0, two = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) zero++;
            if(nums[i] == 1) one++;
            if(nums[i] == 2) two++;
        }

        for(int i=0; i<n; i++) {
            if(i < zero) nums[i] = 0;
            else if(i < zero + one) nums[i] = 1;
            else nums[i] = 2;
        }
        //**********************Dutch National Flag Algorithm*************
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while( mid <= high ) {
            if(nums[mid] == 2) {
                swap(nums[mid] , nums[high]);
                high--;
            } else if(nums[mid] == 0) {
                swap(nums[low] , nums[mid]);
                mid++; low++;
            } else { // for nums[mid] == 1
                mid++;
            }
        }

    }
};