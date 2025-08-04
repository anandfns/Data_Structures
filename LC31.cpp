class Solution {
public:
    void nextPermutation(vector<int>& nums) { //TC : O(n) and SC : O(1)
        int n = nums.size();
        int pivot = -1;

        //Finding Pivot
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        int i = 0;
        int j = n - 1;
        if(pivot == -1) {
            // reverse(nums.begin(), nums.end());
            while(i < j) {
                swap(nums[i++] , nums[j--]);

            }
            return;
        }

        //Finding element just greater than pivot
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[pivot] , nums[i]);
                break;
            }
        }
        
        int st = pivot + 1;
        // sort(nums.begin() + pivot + 1, nums.end());
        while(st < j) { // we are using the same j as earlier, because of the block scope thing, our j will not get updated
            swap(nums[st++] , nums[j--]);
        }

        return;
        
    }
};

//************* In c++ STL we got a function to do this all***************
        next_permutation(A.begin() , A.end());